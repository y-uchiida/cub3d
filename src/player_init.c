/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:20:55 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 13:11:37 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool player_init(t_game *game)
{

	/* TODO: 実際には、cubファイルの解析結果を代入する */

	game->player.x = 1280 / 2; /* raycating実装作業のため、仮の値を入れている */
	game->player.y = 800 / 2;  /* raycating実装作業のため、仮の値を入れている */
	game->player.move_direction = 0;
	game->player.turn_direction = 0;
	game->player.rotation_angle = PI / 2;  /* raycating実装作業のため、仮の値を入れている */
	game->player.move_speed = 100;
	game->player.turn_speed = 45 * (PI / 180);

	return (true);
}
