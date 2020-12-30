/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_marker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:10:26 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:06:44 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_sprite_marker(t_game *game)
{
	int		x;
	int		y;
	int		mini_tile;
	t_rect	marker;

	
	if (game->minimap.scale != TILE_SIZE)
		mini_tile = game->minimap.scale;
	else
		mini_tile = TILE_SIZE;

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