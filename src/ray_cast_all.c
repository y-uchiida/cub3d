/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:30:04 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/21 21:47:19 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool		ray_cast_all(t_game *game)
{
	float	ray_angle;
	int		strip_id;

	ray_angle = game->player.rotation_angle + FOV_ANGLE / 2;
	strip_id = 0;
	while(strip_id < game->rays.num)
	{
		ray_cast(game, ray_angle, strip_id);
		ray_angle += FOV_ANGLE / game->rays.num;
		strip_id++;
	}
	return (true);
}