/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_has_vert_wall_interception.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:08:58 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:52:24 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_vert_wall_interseption(t_ray *ray, t_map map,
				float intercept[2], float step[2])
{
	float	next[2];
	float	check[2];

	next[TABINDEX_X] = intercept[TABINDEX_X];
	next[TABINDEX_Y] = intercept[TABINDEX_Y];
	while (map_contain_the_coordinate(next[TABINDEX_X], next[TABINDEX_Y], map))
	{
		check[TABINDEX_Y] = next[TABINDEX_Y];
		if (ray->is_facing_right)
			check[TABINDEX_X] = next[TABINDEX_X];
		else
			check[TABINDEX_X] = next[TABINDEX_X] - 1;
		if (map_has_wall_at(check[TABINDEX_X], check[TABINDEX_Y], &map))
		{
			ray->has_vert_interception = true;
			ray->vert_wall_intercept_x = next[TABINDEX_X];
			ray->vert_wall_intercept_y = next[TABINDEX_Y];
			break ;
		}
		else
		{
			next[TABINDEX_X] += step[TABINDEX_X];
			next[TABINDEX_Y] += step[TABINDEX_Y];
		}
	}
}

void		ray_has_vert_wall_interception(t_ray *ray, t_player player,
									t_map map, float ray_angle)
{
	float	intercept[2];
	float	step[2];

	intercept[TABINDEX_X] = floor(player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_right)
		intercept[TABINDEX_X] += TILE_SIZE;
	intercept[TABINDEX_Y] = player.y + ((intercept[TABINDEX_X] - player.x)
															* tan(ray_angle));
	step[TABINDEX_X] = (ray->is_facing_right) ? TILE_SIZE : -TILE_SIZE;
	step[TABINDEX_Y] = TILE_SIZE * tan(ray_angle);
	if (ray->is_facing_down && step[TABINDEX_Y] < 0)
		step[TABINDEX_Y] = -step[TABINDEX_Y];
	else if (!(ray->is_facing_down) && step[TABINDEX_Y] > 0)
		step[TABINDEX_Y] = -step[TABINDEX_Y];
	ray->has_vert_interception = false;
	set_vert_wall_interseption(ray, map, intercept, step);
	if (ray->has_vert_interception == true)
		ray->vert_wall_dist = distance_between_points(
			player.x,
			player.y,
			ray->vert_wall_intercept_x,
			ray->vert_wall_intercept_y);
	else
		ray->vert_wall_dist = FLT_MAX;
}
