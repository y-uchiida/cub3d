/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conf_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:48:27 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/14 00:11:31 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	set_resolution(t_game *game, const char **splits)
{
	int		i;
	char	*val;

	if (game->mlx.window.width > 0 || game->mlx.window.height > 0)
		return (put_errors(MULTIPLE_RESOLUTION_INPUT));
	i = 0;
	while (*(++splits) != NULL)
	{
		if (i > 1)
			return (put_errors(INVALID_RESOLUTION_INPUT));
		val = (char *)*splits;
		while (*val != '\0')
		{
			if(ft_isdigit(*val) == 0)
				return (put_errors(INVALID_RESOLUTION_INPUT));
			val++;
		}
		(i == 0) ? game->mlx.window.width = ft_atoi(*splits) : 0;
		(i == 1) ? game->mlx.window.height = ft_atoi(*splits) : 0;
		i++;
	}
	if (game->mlx.window.width <= 0 || game->mlx.window.height <= 0)
		return (put_errors(INVALID_RESOLUTION_INPUT));
	return (true);
}

bool		set_conf_items(t_game *game, const char **splits)
{
	if (ft_strncmp(splits[0], "R", 1) == 0)
		return (set_resolution(game, splits));
	return (true);
}
