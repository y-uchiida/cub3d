/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:10:26 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:29 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void		map_render(t_game *game)
{
	int		x;
	int		y;
	t_rect	tile;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			tile.color = BLACK;
			if (game->map.map[y][x] == '0' || game->map.map[y][x] == '2')
				tile.color = WHITE;
			tile.x0 = x * game->minimap.scale * MINIMAP_SCALE_FACTOR;
			tile.y0 = y * game->minimap.scale * MINIMAP_SCALE_FACTOR;
			tile.width = game->minimap.scale * MINIMAP_SCALE_FACTOR;
			tile.height = game->minimap.scale * MINIMAP_SCALE_FACTOR;
			draw_rect(&(game->frame), tile);
		}
	}
}
