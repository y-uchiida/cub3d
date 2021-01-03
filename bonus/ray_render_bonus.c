/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:48:04 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:21 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void		ray_render(t_game *game)
{
	int		i;
	float	mini_tile;
	float	intercept_x;
	float	intercept_y;
	t_line	line;

	mini_tile = game->minimap.scale / (float)TILE_SIZE;
	i = 0;
	while (i < game->rays.num)
	{
		intercept_x = game->rays.ray[i]->wall_intercept_x;
		intercept_y = game->rays.ray[i]->wall_intercept_y;
		line.x0 = game->player.x * mini_tile * MINIMAP_SCALE_FACTOR;
		line.y0 = game->player.y * mini_tile * MINIMAP_SCALE_FACTOR;
		line.x1 = intercept_x * mini_tile * MINIMAP_SCALE_FACTOR;
		line.y1 = intercept_y * mini_tile * MINIMAP_SCALE_FACTOR;
		line.color = RED;
		draw_line(&(game->frame), line);
		i++;
	}
}
