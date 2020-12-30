/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:40:33 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:03:49 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			player_render(t_game *game)
{
	int			mini_tile;
	t_rect		rect;
	t_player	player;

	if (game->minimap.scale != TILE_SIZE)
		mini_tile = game->minimap.scale / TILE_SIZE;
	else
		mini_tile = 1;
	player = game->player;
	rect.x0 = player.x * mini_tile * MINIMAP_SCALE_FACTOR;
	rect.y0 = player.y * mini_tile * MINIMAP_SCALE_FACTOR;
	rect.width = 10 * mini_tile * MINIMAP_SCALE_FACTOR;
	rect.height = 10 * mini_tile * MINIMAP_SCALE_FACTOR;
	rect.color = BLACK;
	draw_rect(&(game->frame), rect);
	return ;
}