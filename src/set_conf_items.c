/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conf_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:48:27 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/31 04:19:34 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	parse_textures(t_game *game, const char **splits)
{
	t_img			*tx;
	bool			result_import_xpm_file;

	if (splits[1] == NULL)
		return (put_errors(ERR_NO_XPM_FILEPATH, "parse_texture"));
	else if (splits[2] != NULL)
		return (put_errors(ERR_MULTIPLE_XPM_FILEPATH, "parse_texture"));
	tx = &(game->texture.sprite);
	ft_strncmp(splits[0], "NO", 2) == 0 ? tx = &(game->texture.wall_no) : tx;
	ft_strncmp(splits[0], "SO", 2) == 0 ? tx = &(game->texture.wall_so) : tx;
	ft_strncmp(splits[0], "WE", 2) == 0 ? tx = &(game->texture.wall_we) : tx;
	ft_strncmp(splits[0], "EA", 2) == 0 ? tx = &(game->texture.wall_ea) : tx;
	if (tx->data != NULL)
		return (put_errors(ERR_DUPLICATE_TEXTURE_INPUT, "parse_textures"));
	result_import_xpm_file = import_xpm_file(game, tx, splits[1]);
	if (result_import_xpm_file == false)
		return (false);
	return (true);
}

bool		set_conf_items(t_game *game, const char **splits)
{
	if (splits[0] == NULL)
		return (true);
	if (ft_strncmp(splits[0], "R", 1) == 0 && ft_strlen(splits[0]) == 1)
		return (resolution_set(&(game->mlx.window), splits));
	else if ((ft_strncmp(splits[0], "F", 1) == 0 && ft_strlen(splits[0]) == 1)
		|| (ft_strncmp(splits[0], "C", 1) == 0 && ft_strlen(splits[0]) == 1))
		return (bg_colors_set(game, splits));
	else if ((ft_strncmp(splits[0], "NO", 2) == 0 && ft_strlen(splits[0]) == 2)
		|| (ft_strncmp(splits[0], "SO", 2) == 0 && ft_strlen(splits[0]) == 2)
		|| (ft_strncmp(splits[0], "WE", 2) == 0 && ft_strlen(splits[0]) == 2)
		|| (ft_strncmp(splits[0], "EA", 2) == 0 && ft_strlen(splits[0]) == 2)
		|| (ft_strncmp(splits[0], "S", 1) == 0 && ft_strlen(splits[0]) == 1))
		return (parse_textures(game, splits));
	else
		return (put_errors(ERR_INVALID_CONF_PARAM, "set_conf_items"));
	return (true);
}
