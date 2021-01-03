/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_colors_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:12:14 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/03 23:22:08 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool			set_back_color(t_color *color, const char **rgb_str)
{
	int				i;
	unsigned int	rgb[3];
	char			*val;

	i = 0;
	while (rgb_str[i] != NULL)
	{
		if (i > 2)
			return (put_errors(ERR_INVALID_COLOR_INPUT, "set_back_color"));
		val = (char *)rgb_str[i];
		while (*val != '\0')
		{
			if (ft_isdigit(*val) == 0)
				return (put_errors(ERR_INVALID_COLOR_INPUT, "set_back_color"));
			val++;
		}
		if ((rgb[i] = (unsigned int)ft_atoi(rgb_str[i])) > 255)
			return (put_errors(ERR_INVALID_COLOR_INPUT, "set_back_color"));
		i++;
	}
	if (i != 3)
		return (put_errors(ERR_INVALID_COLOR_INPUT, "set_back_color"));
	*color = (t_color)create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (true);
}

static bool			inspect_rgb_tmp(char **rgb_str, char *rgb_tmp)
{
	int				i;
	int				j;
	char			*head;

	i = 0;
	j = 0;
	while (ft_strlen(&(rgb_tmp[i])) > 0)
	{
		head = &(rgb_tmp[i]);
		while (rgb_tmp[i] != ',' && rgb_tmp[i] != '\0')
			i++;
		if (rgb_tmp[i] == ',')
			rgb_tmp[i++] = '\0';
		if ((rgb_str[j] = ft_strdup(head)) == NULL)
			return (put_errors(ERR_MALLOC_FAILED, "inspect_rgb_tmp"));
		j++;
		rgb_str[j] = NULL;
		if (j > 3 && ft_strlen(&(rgb_tmp[i])) > 0)
			return (put_errors(ERR_INVALID_COLOR_INPUT, "inspect_rgb_tmp"));
	}
	return (true);
}

static bool			parse_back_colors(const char **splits, char **rgb_str)
{
	char			*rgb_tmp;
	bool			result_inspect_rgb_tmp;

	if (ft_strnstr(splits[1], ",,", ft_strlen(splits[1])) != NULL)
		return (put_errors(ERR_INVALID_COLOR_INPUT, "parse_back_colors"));
	if ((rgb_tmp = ft_strdup(splits[1])) == NULL)
		return (put_errors(ERR_MALLOC_FAILED, "parse_back_colors"));
	result_inspect_rgb_tmp = inspect_rgb_tmp(rgb_str, rgb_tmp);
	free(rgb_tmp);
	if (result_inspect_rgb_tmp == false)
		return (false);
	return (true);
}

static bool			free_rgb_str(char **rgb_str)
{
	int				i;

	i = 0;
	while (rgb_str[i] != NULL)
	{
		free(rgb_str[i]);
		rgb_str[i] = NULL;
		i++;
	}
	free(rgb_str);
	rgb_str = NULL;
	return (true);
}

bool				bg_colors_set(t_game *game, const char **splits)
{
	t_color			*color;
	char			**rgb_str;

	if (splits[2] != NULL ||
		ft_isdigit(splits[1][ft_strlen(splits[1]) - 1]) == 0)
		return (put_errors(ERR_INVALID_COLOR_INPUT, "bg_colors_set"));
	color = &(game->map.floor_color);
	if (ft_strncmp(splits[0], "C", 1) == 0)
		color = &(game->map.ceil_color);
	if (*color != NONE)
		return (put_errors(ERR_DUPLICATE_COLOR_INPUT, "bg_colors_set"));
	if ((rgb_str = (char **)ft_calloc(sizeof(char *), 4)) == NULL)
		return (put_errors(ERR_MALLOC_FAILED, "bg_colors_set"));
	if (parse_back_colors(splits, rgb_str) == false)
	{
		free_rgb_str(rgb_str);
		return (false);
	}
	if (set_back_color(color, (const char**)rgb_str) == false)
	{
		free_rgb_str(rgb_str);
		return (false);
	}
	free_rgb_str(rgb_str);
	return (true);
}
