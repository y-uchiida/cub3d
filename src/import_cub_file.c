/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:15:57 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/31 04:17:15 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int			open_cub_file(char *file_path)
{
	int				fd;

	if (ft_check_extension(file_path, "cub") == false)
	{
		put_errors(ERR_NOT_CUBFILE, "open_cub_file");
		return (-1);
	}
	if ((fd = open(file_path, O_RDONLY)) < 2)
	{
		put_errors(ERR_CANT_OPEN_CUBFILE, "open_cub_file");
		return (-1);
	}
	return (fd);
}

static bool			parse_line(t_game *game, char *line)
{
	char			*data_head;
	char			**splits;
	bool			ret;

	data_head = (char *)line;
	while (*data_head == ' ')
		data_head++;
	if (*data_head == '1' || game->map.rows > 0)
		return (map_parse(game, line));
	splits = ft_split(data_head, ' ');
	ret = set_conf_items(game, (const char **)splits);
	(splits != NULL) ? ft_free_splits(splits) : 0;
	if (ret == false)
		return (false);
	return (true);
}

static bool			read_cub_file(t_game *game, int fd)
{
	int				ret_get_next_line;
	bool			ret_parse_line;
	char			*line;

	while (1)
	{
		ret_get_next_line = get_next_line(fd, &line);
		if (ret_get_next_line == -1)
			return (put_errors(ERR_CUBFILE_READ_FAILED, "read_cub_file"));
		ret_parse_line = parse_line(game, line);
		ft_free_and_set_null(line);
		if (ret_parse_line == false || ret_get_next_line == 0)
			break ;
	}
	if (ret_parse_line == false)
		return (false);
	return (true);
}

static bool			check_conf_params(t_game *game)
{
	if (game->mlx.window.width < 0 || game->mlx.window.height < 0)
		return (put_errors(ERR_NO_RESOL_SETTING, "check_conf_params"));
	if (game->texture.wall_no.ptr == NULL || game->texture.wall_so.ptr == NULL
	|| game->texture.wall_ea.ptr == NULL || game->texture.wall_we.ptr == NULL
	|| game->texture.sprite.ptr == NULL)
		return (put_errors(ERR_NO_TEXTURE_SETTING, "check_conf_params"));
	if (game->map.ceil_color == NONE || game->map.floor_color == NONE)
		return (put_errors(ERR_NO_COLOR_INPUT, "check_conf_params"));
	if (game->map.rows <= 0 || game->map.cols <= 0)
		return (put_errors(ERR_NO_MAP, "check_conf_params"));
	if (game->player.initial_x < 0 || game->player.initial_y < 0)
		return (put_errors(ERR_NO_PLAYER, "check_conf_params"));
	return (true);
}

bool				import_cub_file(t_game *game, char *file_path)
{
	int		fd;
	bool	result_read_cub_file;

	if ((fd = open_cub_file(file_path)) < 0)
		return (false);
	result_read_cub_file = read_cub_file(game, fd);
	close(fd);
	if (result_read_cub_file == false)
		return (false);
	if (check_conf_params(game) == false)
		return (false);
	if (game->map.rows * game->map.cols > (100 * 100))
		return (put_errors(ERR_MAP_TOO_LARGE, "import_cub_file"));
	if (map_closed_check(game) == false)
		return (put_errors(ERR_MAP_NOT_CLOSED, "import_cub_file"));
	return (true);
}
