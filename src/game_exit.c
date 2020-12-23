/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:33:53 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/23 17:05:49 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void show_all_data(t_game *game);

static bool	game_free(t_game *game)
{
	map_free(game->map.map);
	game->map.map = NULL;
	textures_free(game);
	mlx_destroy_image(game->mlx.ptr, game->frame.ptr);
	mlx_destroy_window(game->mlx.ptr, game->mlx.window.ptr);
	mlx_destroy_display(game->mlx.ptr);
	return (true);
}

void		game_exit(t_game *game)
{
	game_free(game);
	
	show_all_data(game);

	exit(0);
	return ;
}