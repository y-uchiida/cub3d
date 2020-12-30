/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 23:49:31 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:42:32 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool				minimap_init(t_game *game)
{
	t_minimap		*minimap;
	t_mlx_window	*window;
	int				px_per_tile;

	window = &(game->mlx.window);
	minimap = &(game->minimap);
	px_per_tile = TILE_SIZE * MINIMAP_SCALE_FACTOR;
	if ((window->width < game->map.rows * px_per_tile) ||
		(window->height < game->map.cols * px_per_tile))
	{
		minimap->scale_x = window->width / game->map.rows;
		minimap->scale_y = window->height / game->map.cols;
		minimap->scale = ft_set_min(minimap->scale_x, minimap->scale_y);
	}
	else
		minimap->scale = TILE_SIZE;
	return (true);
}
