/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calc_distance.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:44:30 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/26 22:06:51 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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