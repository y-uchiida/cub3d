/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_marker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:10:26 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:25 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void		put_sprite_marker(t_game *game)
{
	int		x;
	int		y;
	int		mini_tile;
	t_rect	marker;

	mini_tile = TILE_SIZE;
	if (game->minimap.scale != TILE_SIZE)
		mini_tile = game->minimap.scale;
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			if (game->map.map[y][x] == '2')
			{
				marker.color = BLUE;
				marker.x0 = ((x + 0.5) * mini_tile) * MINIMAP_SCALE_FACTOR;
				marker.y0 = ((y + 0.5) * mini_tile) * MINIMAP_SCALE_FACTOR;
				marker.width = (int)(mini_tile * 0.2 * MINIMAP_SCALE_FACTOR);
				marker.height = (int)(mini_tile * 0.2 * MINIMAP_SCALE_FACTOR);
				draw_rect(&(game->frame), marker);
			}
		}
	}
}
