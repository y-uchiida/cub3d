/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contain_the_coordinate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:15:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:38:23 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	map_contain_the_coordinate(float x, float y, t_map map)
{
	if ((0 <= x && x <= map.cols * TILE_SIZE) &&
		(0 <= y && y <= map.rows * TILE_SIZE))
		return (true);
	return (false);
}
