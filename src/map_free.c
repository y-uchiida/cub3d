/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 03:19:26 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/19 23:42:07 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool		map_free(char **map)
{
	char	**ptr;
	char	*tmp;

	if (map == NULL)
		return (false);
	ptr = map;
	while (*ptr != NULL)
	{
		tmp = *ptr;
		free(*ptr);
		*ptr = NULL;
		*ptr = tmp;
		ptr++;
	}
	free(map);
	map = NULL;
	return (true);
}