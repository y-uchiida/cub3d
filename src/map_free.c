/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 03:19:26 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/31 02:44:25 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool		map_free(char **map)
{
	int	i;

	if (map == NULL)
		return (false);
	i = 0;
	while (map[i] != NULL)
	{
		ft_free_and_set_null(map[i]);
		i++;
	}
	ft_free_and_set_null(map);
	return (true);
}
