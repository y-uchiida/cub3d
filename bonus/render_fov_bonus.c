/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fov_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:54:10 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:20 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static t_img		*get_projection_tex(bool down,
						bool right, bool hit_vert, t_texture *tex)
{
	if (down == true && right == true && hit_vert == true)
		return (&(tex->wall_ea));
	else if (down == true && right == true && hit_vert == false)
		return (&(tex->wall_so));
	else if (down == true && right == false && hit_vert == true)
		return (&(tex->wall_we));
	else if (down == true && right == false && hit_vert == false)
		return (&(tex->wall_so));
	else if (down == false && right == true && hit_vert == true)
		return (&(tex->wall_ea));
	else if (down == false && right == true && hit_vert == false)
		return (&(tex->wall_no));
	else if (down == false && right == false && hit_vert == true)
		return (&(tex->wall_we));
	return ((&tex->wall_no));
}

static void			set_projection_variables(t_game *game, int x,
													t_projection *prj)
{
	t_mlx_window	*window;
	t_player		*player;
	t_ray			*ray;

	window = &(game->mlx.window);
	player = &(game->player);
	ray = game->rays.ray[x];
	prj->perp_dist = ray->dist * cos(ray->angle - player->rotation_angle);
	prj->actual_height = (TILE_SIZE / prj->perp_dist) * window->dist_prj_plane;
	prj->drawing_height = (int)prj->actual_height;
	prj->top_px = (window->height / 2) - (prj->drawing_height / 2);
	prj->top_px = (prj->top_px < 0) ? 0 : prj->top_px;
	prj->bottom_px = (window->height / 2) + (prj->drawing_height / 2);
	if (prj->bottom_px > window->height)
		prj->bottom_px = window->height;
	prj->tex = get_projection_tex(ray->is_facing_down,
		ray->is_facing_right, ray->wall_hit_vertical, &(game->texture));
}

static void			get_texture_pixel_color(t_game *game, int x, int y,
													t_projection *prj)
{
	t_ray			*ray;
	float			intensity;
	float			propotion_x;
	float			propotion_y;

	ray = game->rays.ray[x];
	prj->distance_from_top = (game->mlx.window.height / 2)
							- (prj->drawing_height / 2);
	propotion_y = (y - prj->distance_from_top) / (float)prj->drawing_height;
	prj->tex_offset_y = (int)(prj->tex->height * propotion_y);
	if (ray->wall_hit_vertical)
		propotion_x = (fmodf(ray->wall_intercept_y, TILE_SIZE) / TILE_SIZE);
	else
		propotion_x = (fmodf(ray->wall_intercept_x, TILE_SIZE) / TILE_SIZE);
	prj->tex_offset_x = (int)(prj->tex->width * propotion_x);
	if ((ray->is_facing_down && !ray->wall_hit_vertical) ||
		(!ray->is_facing_right && ray->wall_hit_vertical))
		prj->tex_offset_x = prj->tex->width - prj->tex_offset_x - 1;
	prj->texture_px_color =
		image_get_pixel_color(prj->tex_offset_x, prj->tex_offset_y, prj->tex);
	if (ray->wall_hit_vertical)
		color_change_intensity(&(prj->texture_px_color), 0.8);
	intensity = (ray->dist > 400.0) ? 400.0 / ray->dist : 1.0;
	intensity = ft_set_max_f(0.40, intensity);
	color_change_intensity(&(prj->texture_px_color), intensity);
}

static void			set_tex_color(t_game *game, int x, int y,
												t_projection *prj)
{
	t_img			*frame;

	frame = &(game->frame);
	if (y < prj->top_px)
		image_put_pixel_color(frame, x, y, game->map.ceil_color);
	else if (prj->top_px <= y && y < prj->bottom_px)
	{
		get_texture_pixel_color(game, x, y, prj);
		image_put_pixel_color(frame, x, y, prj->texture_px_color);
	}
	else
		image_put_pixel_color(frame, x, y, game->map.floor_color);
}

void				render_fov(t_game *game)
{
	int				x;
	int				y;
	t_projection	prj;

	x = 0;
	while (x < game->rays.num)
	{
		set_projection_variables(game, x, &prj);
		y = 0;
		while (y < game->mlx.window.height)
		{
			set_tex_color(game, x, y, &prj);
			y++;
		}
		x++;
	}
	return ;
}
