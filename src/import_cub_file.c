/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:15:57 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/16 23:53:58 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	open_cub_file(char *file_path)	
{
	int fd;

	if (ft_check_extension(file_path, "cub") == false)
	{
		put_errors(ERR_NOT_CUBFILE);
		return (-1);
	}
	if ((fd = open(file_path, O_RDONLY)) < 2)
	{
		put_errors(ERR_CANT_OPEN_CUBFILE);
		put_error_details("open_cub_file");
		return (-1);
	}
	return (fd);
}

static bool	parse_line(t_game *game, const char *line)
{
	char 			*data_head;
	static bool		still_mapping = false;
	char			**splits;
	bool			ret;

	data_head = (char *)line;
	while (*data_head == ' ')
		data_head++;
	if (*data_head == '1' || still_mapping == true)
		return (map_parse(game, line));
	splits = ft_split(data_head, ' ');
	ret = set_conf_items(game, (const char **)splits);
	(splits != NULL) ? ft_free_splits(splits) : 0;
	if (ret == false)
		return (false);
	return (true);
}

static bool	read_cub_file(t_game *game, int fd)
{
	int		ret_get_next_line;
	bool	ret_parse_line;
	char	*line;

	while (1)
	{
		ret_get_next_line = get_next_line(fd, &line);
		if (ret_get_next_line == -1)
		{
			put_errors(ERR_CUBFILE_READ_FAILED);
			put_error_details("read_cub_file");
			return (false);
		}
		ret_parse_line = parse_line(game, line);
		free(line);
		if (ret_parse_line == false || ret_get_next_line == 0)
			break ;
	}
	if (ret_parse_line == false)
		return (false);
	return (true);
}

bool		import_cub_file(t_game *game, char *file_path)
{
	int		fd;
	bool	result_read_cub_file;

	if ((fd = open_cub_file(file_path)) < 0)
		return (false);	
	result_read_cub_file = read_cub_file(game, fd);
	close(fd);
	if (result_read_cub_file == false)
		return (false);

	return (true);
}
