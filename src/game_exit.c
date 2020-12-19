/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:33:53 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/19 18:17:59 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	game_free(t_game *game)
{
	map_free(game->map.map);
	mlx_destroy_window(game->mlx.ptr, game->mlx.window.ptr);
	mlx_destroy_display(game->mlx.ptr);
	return (true);
}

void		game_exit(t_game *game)
{
	printf("game_exit\n");
	game_free(game);
	exit(0);
	return ;
}