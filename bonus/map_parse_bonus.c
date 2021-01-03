/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:05:58 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:30 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static bool		extend_map_col(t_map *map)
{
	int			i;
	char		**new_map;

	if ((new_map = (char **)ft_calloc(sizeof(char *), map->rows + 1)) == NULL)
		return (put_errors(ERR_MALLOC_FAILED, "extend_map_col"));
	i = 0;
	while (i < map->rows - 1)
	{
		new_map[i] = (char *)ft_calloc(sizeof(char), map->cols + 1);
		if (new_map[i] == NULL)
		{
			map_free(new_map);
			return (put_errors(ERR_MALLOC_FAILED, "extend_map_col"));
		}
		ft_strlcpy(new_map[i], map->map[i], map->cols + 1);
		i++;
	}
	map_free(map->map);
	map->map = new_map;
	return (true);
}

static bool		add_map_row(t_map *map, char *line)
{
	int		i;
	char	**new_map;
	char	**map_ptr;
	char	*new_row;

	new_map = (char **)ft_calloc(map->rows + 1, sizeof(char *));
	if (new_map == NULL)
		return (put_errors(ERR_MALLOC_FAILED, "add_map_row"));
	map_ptr = map->map;
	i = -1;
	while (map_ptr[++i] != NULL)
		new_map[i] = map_ptr[i];
	new_row = NULL;
	new_row = (char *)ft_calloc(map->cols + 1, sizeof(char));
	if (new_row == NULL)
	{
		map_free(new_map);
		return (put_errors(ERR_MALLOC_FAILED, "add_map_row"));
	}
	ft_strlcpy(new_row, line, map->cols + 1);
	new_map[i] = new_row;
	map_ptr = map->map;
	map->map = new_map;
	ft_free_and_set_null(map_ptr);
	return (true);
}

static bool		set_player_position(t_game *game, int col, float dir)
{
	if (game->player.x != FLT_MIN || game->player.y != FLT_MIN)
		return (put_errors(ERR_DUPLICATE_MAP_INPUT, "set_player_position"));
	game->player.x = (col + 0.5) * TILE_SIZE;
	game->player.y = (game->map.rows - 0.5) * TILE_SIZE;
	game->player.initial_x = col;
	game->player.initial_y = game->map.rows - 1;
	game->player.rotation_angle = dir;
	return (true);
}

static bool		inspect_new_line(t_game *game, char *line)
{
	int			col;
	float		dir;
	const char	valid_chars[8] = {" 012NSEW"};

	col = -1;
	while (line[++col] != '\0')
	{
		if (ft_strchr(valid_chars, line[col]) == NULL)
			return (put_errors(ERR_INVALID_MAP_INPUT, "inspect_new_line"));
		dir = -1;
		(line[col] == 'E') ? dir = PI * 0 / 2 : dir;
		(line[col] == 'S') ? dir = PI * 1 / 2 : dir;
		(line[col] == 'W') ? dir = PI * 2 / 2 : dir;
		(line[col] == 'N') ? dir = PI * 3 / 2 : dir;
		if (dir != -1.0)
		{
			if (set_player_position(game, col, dir) == false)
				return (false);
			line[col] = '0';
		}
		if (line[col] == '2')
			if ((sprite_new_item(game, col, game->map.rows - 1)) == false)
				return (false);
	}
	return (true);
}

bool			map_parse(t_game *game, char *line)
{
	int			line_len;

	(game->map.rows)++;
	line_len = ft_strlen(line);
	if (inspect_new_line(game, line) == false)
		return (false);
	if (game->map.map == NULL)
	{
		game->map.cols = line_len;
		if ((game->map.map = (char **)ft_calloc(2, sizeof(char *))) == NULL)
			return (put_errors(ERR_MALLOC_FAILED, "map_parse"));
		if ((*(game->map.map) = ft_strdup(line)) == NULL)
			return (put_errors(ERR_MALLOC_FAILED, "map_parse"));
		return (true);
	}
	if (line_len > game->map.cols)
	{
		game->map.cols = line_len;
		if (extend_map_col(&(game->map)) == false)
			return (false);
	}
	if (add_map_row(&(game->map), (char *)line) == false)
		return (false);
	return (true);
}
