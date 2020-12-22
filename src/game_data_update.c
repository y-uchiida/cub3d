/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:26:21 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/21 21:49:10 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		game_data_update(t_game *game)
{
	if (game->running == false)
		game_exit(game);
	else
	{
		player_move(game);
		ray_cast_all(game);
	}
	return (EXIT_SUCCESS);
}