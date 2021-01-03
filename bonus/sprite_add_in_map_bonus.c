/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_add_in_map_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 04:07:37 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:17 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool		sprite_add_in_map(t_game *game)
{
	float	new[2];
	int		grid[2];

	new[TABINDEX_X] = game->player.x + cos(game->player.rotation_angle) * 80.0;
	new[TABINDEX_Y] = game->player.y + sin(game->player.rotation_angle) * 80.0;
	if (map_has_wall_at(new[TABINDEX_X], new[TABINDEX_Y],
										&(game->map)) == false)
	{
		grid[TABINDEX_X] = (int)floor(new[TABINDEX_X] / TILE_SIZE);
		grid[TABINDEX_Y] = (int)floor(new[TABINDEX_Y] / TILE_SIZE);
		game->map.map[grid[TABINDEX_Y]][grid[TABINDEX_X]] = '2';
		if (sprite_new_item(game, grid[TABINDEX_X], grid[TABINDEX_Y]) == false)
		{
			game_exit(game);
			return (false);
		}
	}
	else
		return (false);
	return (true);
}
