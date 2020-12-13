/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:15:57 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 23:20:12 by yoguchi          ###   ########.fr       */
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

static void		free_splits(char **splits)
{
	char	**ptr;

	printf("start free_splits.\n");

	ptr = splits;
	while (*ptr != NULL)
	{
		printf("now free \"%s\"\n", *ptr);
		free(*ptr);
		ptr++;
	}
	free(splits);
	splits = NULL;
	return ;
}

static bool	parse_line(t_game *game, const char *line)
{
	char 			*p_line;
	static bool		still_mapping = false;
	char			**splits;
	bool			ret;

	p_line = (char *)line;
	while (*p_line == ' ')
		p_line++;
	if (*p_line == '1' || still_mapping == true)
		return (map_parse(game, line));
	splits = ft_split(p_line, ' ');
	ret = set_conf_items(game, (const char **)splits);
	free_splits(splits);
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
			put_error_details("parse_cub_file");
			return (false);
		}
		else if (ret_get_next_line == 0)
			break;
		ret_parse_line = parse_line(game, line);
		free(line);
		if (ret_parse_line == false)
			break ;
	}
	if (ret_parse_line == false)
		return (false);
	return (true);
}

bool		import_cub_file(t_game *game, char *file_path)
{
	int		fd;
	bool	ret_read_cub_file;

	if ((fd = open_cub_file(file_path)) < 0)
		return (false);	
	ret_read_cub_file = read_cub_file(game, fd);
	close(fd);
	if (ret_read_cub_file == false)
		return (false);
	game->mlx.window.width = 1280;
	game->mlx.window.height = 800;

	return (true);
}