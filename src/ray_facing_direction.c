/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_facing_direction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 03:02:49 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/26 01:25:53 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ray_facing_direction(t_ray *ray, float ray_angle)
{
	if (0 < ray_angle && ray_angle < PI)
		ray->is_facing_down = true;
	else
		ray->is_facing_down =  false;
	if (ray_angle < 0.5 * PI || 1.5 * PI < ray_angle)
		ray->is_facing_right = true;
	else
		ray->is_facing_right = false;
}
