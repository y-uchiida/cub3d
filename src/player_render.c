/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:40:33 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/24 01:45:41 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		player_render(t_game *game)
{
	t_rect	rect;

	rect.x0 = game->player.x * MINIMAP_SCALE_FACTOR;
	rect.y0 = game->player.y * MINIMAP_SCALE_FACTOR;
	rect.width = 10 * MINIMAP_SCALE_FACTOR;
	rect.height = 10 * MINIMAP_SCALE_FACTOR;
	rect.color = RED;
	draw_rect(&(game->frame), rect);
	return ;
}