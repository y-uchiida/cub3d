/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_has_horz_wall_interception.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:05:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:51:39 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_horz_wall_interseption(t_ray *ray, t_map map,
				float intercept[2], float step[2])
{
	float	next[2];
	float	check[2];

	next[TABINDEX_X] = intercept[TABINDEX_X];
	next[TABINDEX_Y] = intercept[TABINDEX_Y];
	while (map_contain_the_coordinate(next[TABINDEX_X], next[TABINDEX_Y], map))
	{
		check[TABINDEX_X] = next[TABINDEX_X];
		check[TABINDEX_Y] = next[TABINDEX_Y] + ((ray->is_facing_down) ? 0 : -1);
		if (map_has_wall_at(check[TABINDEX_X], check[TABINDEX_Y], &map))
		{
			ray->has_horz_interception = true;
			ray->horz_wall_intercept_x = next[TABINDEX_X];
			ray->horz_wall_intercept_y = next[TABINDEX_Y];
			break ;
		}
		else
		{
			next[TABINDEX_X] += step[TABINDEX_X];
			next[TABINDEX_Y] += step[TABINDEX_Y];
		}
	}
}

void		ray_has_horz_wall_interception(t_ray *ray, t_player player,
									t_map map, float ray_angle)
{
	float	intercept[2];
	float	step[2];

	intercept[TABINDEX_Y] = floor(player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_down)
		intercept[TABINDEX_Y] += TILE_SIZE;
	intercept[TABINDEX_X] = player.x + ((intercept[TABINDEX_Y] - player.y)
															/ tan(ray_angle));
	step[TABINDEX_Y] = ray->is_facing_down ? TILE_SIZE : -TILE_SIZE;
	step[TABINDEX_X] = TILE_SIZE / tan(ray_angle);
	if (ray->is_facing_right && step[TABINDEX_X] < 0)
		step[TABINDEX_X] = -step[TABINDEX_X];
	else if (!(ray->is_facing_right) && step[TABINDEX_X] > 0)
		step[TABINDEX_X] = -step[TABINDEX_X];
	ray->has_horz_interception = false;
	set_horz_wall_interseption(ray, map, intercept, step);
	if (ray->has_horz_interception == true)
		ray->horz_wall_dist = distance_between_points(
			player.x,
			player.y,
			ray->horz_wall_intercept_x,
			ray->horz_wall_intercept_y);
	else
		ray->horz_wall_dist = FLT_MAX;
}
