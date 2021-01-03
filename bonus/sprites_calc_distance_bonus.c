/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calc_distance_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:44:30 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:16 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool		sprites_calc_distance(t_game *game)
{
	t_sprite	*sprite;
	t_player	player;

	sprite = game->sprites.sprite;
	player = game->player;
	while (sprite != NULL)
	{
		sprite->dist = distance_between_points(player.x, player.y,
												sprite->x, sprite->y);
		sprite = sprite->next;
	}
	return (true);
}
