/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_wall_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:50:36 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:39:14 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool		map_has_wall_at(float x, float y, t_map *map)
{
	int map_grid_index_x;
	int map_grid_index_y;

	if ((x < 0 || map->cols * TILE_SIZE < x) ||
		(y < 0 || map->rows * TILE_SIZE < y))
		return (true);
	map_grid_index_x = floor(x / TILE_SIZE);
	map_grid_index_y = floor(y / TILE_SIZE);
	if ((map_grid_index_x <= 0 || map->cols <= map_grid_index_x) ||
		(map_grid_index_y <= 0 || map->rows <= map_grid_index_y))
		return (true);
	if (map->map[map_grid_index_y][map_grid_index_x] == '0' ||
		map->map[map_grid_index_y][map_grid_index_x] == '2')
		return (false);
	return (true);
}
