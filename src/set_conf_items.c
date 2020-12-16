/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conf_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:48:27 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/16 23:37:13 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	set_resolution(t_game *game, const char **splits)
{
	int		i;
	char	*val;

	if (game->mlx.window.width > 0 || game->mlx.window.height > 0)
		return (put_errors(ERR_MULTIPLE_RESOL_INPUT));
	i = 1;
	while (splits[i] != NULL)
	{
		if (i > 2)
			return (put_errors(ERR_INVALID_RESOL_INPUT));
		val = (char *)splits[i];
		while (*val != '\0')
		{
			if(ft_isdigit(*val) == 0)
				return (put_errors(ERR_INVALID_RESOL_INPUT));
			val++;
		}
		(i == 1) ? game->mlx.window.width = ft_atoi(splits[i]) : 0;
		(i == 2) ? game->mlx.window.height = ft_atoi(splits[i]) : 0;
		i++;
	}
	if (game->mlx.window.width <= 0 || game->mlx.window.height <= 0)
		return (put_errors(ERR_INVALID_RESOL_INPUT));
	return (true);
}

static bool set_back_color(t_color *color, const char **rgb_str)
{
	int				i;
	unsigned int	rgb[3];
	char			*val;

	i = 0;
	while (rgb_str[i] != NULL)
	{

		if (i > 2)
			return (put_errors(ERR_INVALID_COLOR_INPUT));
		val = (char *)rgb_str[i];
		while (*val != '\0')
		{
			if(ft_isdigit(*val) == 0)
				return (put_errors(ERR_INVALID_COLOR_INPUT));
			val++;
		}
		if ((rgb[i] = (unsigned int)ft_atoi(rgb_str[i])) > 255)
			return (put_errors(ERR_INVALID_COLOR_INPUT));
		i++;
	}
	*color = (t_color)create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (true);
}

static bool	parse_back_colors(t_game *game, const char **splits)
{
	bool		result_set_back_color;
	t_color		*color;
	char		**rgb_str;

	if (splits[2] != NULL)
		return (put_errors(ERR_INVALID_COLOR_INPUT));
	color = &(game->map.floor_color);
	if(ft_strncmp(splits[0], "C", 1) == 0)
		color = &(game->map.ceil_color);
	if (*color != NONE)
		return (put_errors(ERR_DUPLICATE_COLOR_INPUT));
	rgb_str = ft_split(splits[1], ',');
	result_set_back_color = set_back_color(color, (const char**)rgb_str);
	ft_free_splits(rgb_str);
	if (result_set_back_color == false)
		return (false);
	return (true);
}

static bool	parse_textures(t_game *game, const char **splits)
{
	t_img			*tx;
	bool			result_import_xpm_file;

	tx = &(game->texture.sprite);
	ft_strncmp(splits[0], "NO", 2) == 0 ? tx = &(game->texture.noth_wall) : tx;
	ft_strncmp(splits[0], "SO", 2) == 0 ? tx = &(game->texture.south_wall) : tx;
	ft_strncmp(splits[0], "WE", 2) == 0 ? tx = &(game->texture.west_wall) : tx;
	ft_strncmp(splits[0], "EA", 2) == 0 ? tx = &(game->texture.east_wall) : tx;
	if (tx->data != NULL)
		return (put_errors(ERR_DUPLICATE_TEXTURE_INPUT));
	result_import_xpm_file = import_xpm_file(game, tx, splits[1]);
	if (result_import_xpm_file == false)
		return (false);
	return (true);
}

bool		set_conf_items(t_game *game, const char **splits)
{
	if (splits[0] == NULL)
		return (true);
	if (ft_strncmp(splits[0], "R", 1) == 0)
		return (set_resolution(game, splits));
	if (game->mlx.window.width > game->mlx.window.max_width)
		game->mlx.window.width = game->mlx.window.max_width;
	if (game->mlx.window.height > game->mlx.window.max_height)
		game->mlx.window.height = game->mlx.window.max_height;
	if ((ft_strncmp(splits[0], "F", 1) == 0) || 
		(ft_strncmp(splits[0], "C", 1) == 0))
		return (parse_back_colors(game, splits));
	if ((ft_strncmp(splits[0], "NO", 2) == 0) || 
		(ft_strncmp(splits[0], "SO", 2) == 0) ||
		(ft_strncmp(splits[0], "WE", 2) == 0) ||
		(ft_strncmp(splits[0], "EA", 2) == 0) ||
		(ft_strncmp(splits[0], "S",  1) == 0))
		return (parse_textures(game, splits));
	return (true);
}
