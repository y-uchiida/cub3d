/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_facing_direction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 03:02:49 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/20 19:19:40 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ray_facing_direction(t_ray *ray, float ray_angle)
{

	if (ray_angle > 0 && ray_angle < PI)
		ray->is_facing_down = true;
	else
		ray->is_facing_down =  false;
	if (ray_angle < 1 / 2 * PI || ray_angle > 3 / 2 * PI)
		ray->is_facing_right = true;
	else
		ray->is_facing_right = false;
}
