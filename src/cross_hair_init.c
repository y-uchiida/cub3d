/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_hair_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 05:24:59 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:33:23 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool			cross_hair_init(t_game *game)
{
	if (import_xpm_file(game, game->cross_hair->img,
									"./img/cross_hair.xpm") == false)
		game_exit(game);
	game->cross_hair->x = game->mlx.window.width / 2;
	game->cross_hair->y = game->mlx.window.height / 2;
	game->cross_hair->width = 32;
	game->cross_hair->height = 32;
	return (true);
}
