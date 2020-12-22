/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:20:55 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/20 02:34:27 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool player_init(t_game *game)
{
	game->player.move_direction = 0;
	game->player.turn_direction = 0;
	game->player.move_speed = 0.1;
	game->player.turn_speed = 30 * (PI / 180);

	return (true);
}
