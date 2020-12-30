/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:33:53 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:29:09 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool		game_free(t_game *game)
{
	map_free(game->map.map);
	game->map.map = NULL;
	frame_free(game);
	textures_free(game);
	sprites_free(game);
	if (game->mlx.window.ptr != NULL)
		mlx_destroy_window(game->mlx.ptr, game->mlx.window.ptr);
	if (game->mlx.ptr != NULL)
		mlx_destroy_display(game->mlx.ptr);
	return (true);
}

void			game_exit(t_game *game)
{
	game_free(game);
	show_all_data(game);
	exit(0);
	return ;
}
