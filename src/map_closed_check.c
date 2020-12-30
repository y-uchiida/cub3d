/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 04:05:14 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:38:07 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	map_copy_free(char **map_copy)
{
	int		n;

	n = 0;
	while (map_copy[n] != NULL)
	{
		free(map_copy[n]);
		map_copy[n] = NULL;
		n++;
	}
	free(map_copy);
	map_copy = NULL;
}

static bool	create_map_copy(t_game *game, char ***map_copy)
{
	int		n;
	int		rows;

	rows = game->map.rows;
	if ((*map_copy = (char**)ft_calloc(sizeof(char *), rows + 1)) == NULL)
	{
		put_errors(ERR_MALLOC_FAILED, "map_closed_check");
		game_exit(game);
		return (EXIT_FAILURE);
	}
	n = -1;
	while (++n < rows)
	{
		if (((*map_copy)[n] = ft_strdup(game->map.map[n])) == NULL)
		{
			put_errors(ERR_MALLOC_FAILED, "map_closed_check");
			map_copy_free(*map_copy);
			game_exit(game);
			return (EXIT_FAILURE);
		}
	}
	return (true);
}

static bool	depth_searh(t_game *game, char **map_copy, int x, int y)
{
	int		rows;
	int		cols;

	rows = game->map.rows - 1;
	cols = game->map.cols - 1;
	if ((y == 0 || y == rows || x == 0 || x == cols) && map_copy[y][x] != '1')
		return (false);
	map_copy[y][x] = 'X';
	if (y > 0 && map_copy[y - 1][x] != '1' && map_copy[y - 1][x] != 'X')
		if (depth_searh(game, map_copy, x, y - 1) == false)
			return (false);
	if (x < cols && map_copy[y][x + 1] != '1' && map_copy[y][x + 1] != 'X')
		if (depth_searh(game, map_copy, x + 1, y) == false)
			return (false);
	if (y < rows && map_copy[y + 1][x] != '1' && map_copy[y + 1][x] != 'X')
		if (depth_searh(game, map_copy, x, y + 1) == false)
			return (false);
	if (x > 0 && map_copy[y][x - 1] != '1' && map_copy[y][x - 1] != 'X')
		if (depth_searh(game, map_copy, x - 1, y) == false)
			return (false);
	return (true);
}

bool		map_closed_check(t_game *game)
{
	char		**map_copy;
	t_player	player;

	map_copy = NULL;
	if (create_map_copy(game, &map_copy) == false)
		return (false);
	player = game->player;
	if (depth_searh(game, map_copy,
					player.initial_x, player.initial_y) == false)
	{
		put_errors(ERR_MAP_NOT_CLOSED, "map_closed_check");
		map_copy_free(map_copy);
		game_exit(game);
		return (false);
	}
	map_copy_free(map_copy);
	return (true);
}
