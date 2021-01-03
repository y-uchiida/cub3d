/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_set_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 22:46:15 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:19 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static bool	resolution_input(t_mlx_window *window, const char **splits)
{
	int		i;
	long	tmp;
	char	*val;

	i = 0;
	while (splits[++i] != NULL)
	{
		if (i > 2)
			return (put_errors(ERR_INVALID_RESOL_INPUT, "resolution_input"));
		val = (char *)splits[i];
		while (*val != '\0')
		{
			if (ft_isdigit(*val) == 0)
			{
				return (put_errors(ERR_INVALID_RESOL_INPUT,
													"resolution_input"));
			}
			val++;
		}
		if ((tmp = ft_atoi(splits[i])) > INT_MAX)
			return (put_errors(ERR_RESOL_TOO_LARGE, "resolution_input"));
		(i == 1) ? window->width = tmp : 0;
		(i == 2) ? window->height = tmp : 0;
	}
	return (true);
}

bool		resolution_set(t_mlx_window *window, const char **splits)
{
	if (window->width > 0 || window->height > 0)
		return (put_errors(ERR_MULTIPLE_RESOL_INPUT, "resolution_set"));
	if (resolution_input(window, splits) == false)
		return (false);
	if (window->width > INT_MAX || window->height > INT_MAX)
		return (put_errors(ERR_RESOL_TOO_LARGE, "resolutuin_set"));
	window->width = ft_set_min(window->width, window->max_width);
	window->height = ft_set_min(window->height, window->max_height);
	return (true);
}
