/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:48:04 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:56:33 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ray_render(t_game *game)
{
	int		i;
	int		mini_tile;
	float	intercept_x;
	float	intercept_y;
	t_line	line;

	if (game->minimap.scale != TILE_SIZE)
		mini_tile = game->minimap.scale / TILE_SIZE;
	else
		mini_tile = 1;
	i = 0;
	intercept_x = game->rays.ray[i]->wall_intercept_x;
	intercept_y = game->rays.ray[i]->wall_intercept_y;
	while (i < game->rays.num)
	{
		line.x0 = game->player.x * mini_tile * MINIMAP_SCALE_FACTOR;
		line.y0 = game->player.y * mini_tile * MINIMAP_SCALE_FACTOR;
		line.x1 = intercept_x * mini_tile * MINIMAP_SCALE_FACTOR;
		line.y1 = intercept_y * mini_tile * MINIMAP_SCALE_FACTOR;
		line.color = RED;
		draw_line(&(game->frame), line);
		i++;
	}
}
