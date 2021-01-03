/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 02:52:03 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:59:44 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	compare_horz_vert_interception(t_ray *ray)
{
	if (ray->horz_wall_dist < ray->vert_wall_dist)
	{
		ray->wall_intercept_x = ray->horz_wall_intercept_x;
		ray->wall_intercept_y = ray->horz_wall_intercept_y;
		ray->dist = ray->horz_wall_dist;
		ray->wall_hit_vertical = false;
	}
	else
	{
		ray->wall_intercept_x = ray->vert_wall_intercept_x;
		ray->wall_intercept_y = ray->vert_wall_intercept_y;
		ray->dist = ray->vert_wall_dist;
		ray->wall_hit_vertical = true;
	}
}

void		ray_cast(t_game *game, float ray_angle, int strip_id)
{
	game->rays.ray[strip_id]->angle = ray_angle;
	ray_facing_direction(game->rays.ray[strip_id], ray_angle);
	ray_has_horz_wall_interception(game->rays.ray[strip_id], game->player,
									game->map, ray_angle);
	ray_has_vert_wall_interception(game->rays.ray[strip_id], game->player,
									game->map, ray_angle);
	compare_horz_vert_interception(game->rays.ray[strip_id]);
	return ;
}
