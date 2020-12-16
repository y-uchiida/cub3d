/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:05:58 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/17 00:54:05 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// static char		*new_map_row(int col)
// {
// 	char *ret;

// 	ret = (char *)ft_calloc(sizeof(char), col + 1);
// 	return (ret);
// }

static bool		extend_map_col(t_map *map)
{
	int			i;
	char		**new_map;

	if ((new_map = (char **)ft_calloc(sizeof(char *), map->rows + 1)) == NULL)
	{
		put_errors(ERR_MALLOC_FAILED);
		put_error_details("map_renew");
		return (false);
	}
	i = 0;
	while (i < map->rows)
	{
		printf("new_map[%d], %p\n", i, new_map[i]);
		new_map[i] = (char *)ft_calloc(sizeof(char), map->cols + 1);
		if (new_map[i] == )
		i++;
	}
	return (true);
}

bool			map_parse(t_game *game, const char *line)
{
	// int			i;
	int			line_len;

	(game->map.rows)++;
	line_len = ft_strlen(line);

	if (line_len > game->map.cols)
	{
		game->map.cols = line_len;
		extend_map_col(&(game->map));
	}
	else
		// add_map_row(*(game->map));

	printf("map: %s\n", line);

	return (true);
}
