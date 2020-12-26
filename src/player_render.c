/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:40:33 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/26 16:24:36 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			player_render(t_game *game)
{
	t_rect		rect;
	t_player	player;

	player = game->player;
	rect.x0 = player.x * MINIMAP_SCALE_FACTOR;
	rect.y0 = player.y * MINIMAP_SCALE_FACTOR;
	rect.width = 10 * MINIMAP_SCALE_FACTOR;
	rect.height = 10 * MINIMAP_SCALE_FACTOR;
	rect.color = BLACK;
	draw_rect(&(game->frame), rect);
	return ;
}