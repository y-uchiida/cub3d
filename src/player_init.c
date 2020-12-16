/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:20:55 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/15 13:23:57 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool player_init(t_game *game)
{

	game->player.move_direction = 0;
	game->player.turn_direction = 0;
	game->player.rotation_angle = PI / 2;  /* raycating実装作業のため、仮の値を入れている */
	game->player.move_speed = 100;
	game->player.turn_speed = 45 * (PI / 180);

	return (true);
}
