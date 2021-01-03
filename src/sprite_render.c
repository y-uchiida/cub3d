/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:05:17 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 05:10:58 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void			set_sprite_position_data(t_game *game,
										t_sprite *sprite, t_projection *prj)
{
	t_player		player;
	t_mlx_window	*window;

	player = game->player;
	window = &(game->mlx.window);
	sprite->angle = atan2((sprite->y - player.y), (sprite->x - player.x))
													- player.rotation_angle;
	sprite->angle_from_left_side = sprite->angle + (game->fov_angle / 2);
	normalize_angle(&(sprite->angle_from_left_side));
	if (sprite->angle_from_left_side > ft_deg_to_rad(180))
		sprite->angle_from_left_side -= ft_deg_to_rad(360);
	sprite->px_from_left_side = (int)(sprite->angle_from_left_side
										/ (game->fov_angle / window->width));
	prj->tex = &(game->texture.sprite);
	prj->perp_dist = sprite->dist * cos(sprite->angle - player.rotation_angle);
	prj->actual_height = (TILE_SIZE / sprite->dist) * window->dist_prj_plane;
	prj->drawing_height = (int)prj->actual_height;
	prj->top_px = (window->height / 2) - (prj->drawing_height / 2);
	prj->bottom_px = (window->height / 2) + (prj->drawing_height / 2);
	if (prj->bottom_px > window->height)
		prj->bottom_px = window->height;
	prj->drawing_width = prj->drawing_height;
}

static void			get_sprite_pixel_color(t_sprite *sprite, int x, int y,
														t_projection *prj)
{
	float			dist;
	float			intensity;
	float			propotion_x;
	float			propotion_y;

	dist = sprite->dist;
	propotion_x = (float)x / (float)prj->drawing_width;
	propotion_y = (float)y / (float)prj->drawing_height;
	prj->tex_offset_x = (int)(prj->tex->width * propotion_x);
	prj->tex_offset_y = (int)(prj->tex->height * propotion_y);
	prj->texture_px_color = image_get_pixel_color(prj->tex_offset_x,
												prj->tex_offset_y, prj->tex);
	intensity = (dist > 400.0) ? 400.0 / dist : 1.0;
	intensity = ft_set_max_f(0.40, intensity);
	color_change_intensity(&(prj->texture_px_color), intensity);
}

static void			put_sprite_in_frame(t_game *game, t_sprite *sprite,
														t_projection *prj)
{
	int				x;
	int				y;

	x = -1;
	while (++x < game->mlx.window.width)
	{
		if (x < sprite->px_from_left_side - (prj->drawing_width / 2))
			continue ;
		if (sprite->px_from_left_side + (prj->drawing_width / 2) < x)
			break ;
		y = -1;
		while (++y < game->mlx.window.height)
		{
			if (y < prj->top_px)
				continue ;
			if (prj->top_px + prj->drawing_height - 1 < y)
				break ;
			get_sprite_pixel_color(sprite, x - (sprite->px_from_left_side
						- (prj->drawing_width / 2)), y - prj->top_px, prj);
			if ((sprite->dist < game->rays.ray[x]->dist) &&
				(get_t(prj->texture_px_color) == 0))
				image_put_pixel_color(&(game->frame), x, y,
														prj->texture_px_color);
		}
	}
}

void				sprite_render(t_game *game)
{
	t_sprite		*sprite;
	t_projection	prj;

	sprite = game->sprites.sprite;
	while (sprite != NULL)
	{
		set_sprite_position_data(game, sprite, &prj);
		put_sprite_in_frame(game, sprite, &prj);
		sprite = sprite->next;
	}
	return ;
}
