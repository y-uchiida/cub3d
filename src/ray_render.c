/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:48:04 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/24 01:58:08 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ray_render(t_game *game)
{
	int		i;
	t_line	line;

	i = 0;
	while (i < game->rays.num)
	{
		line.x0 = game->player.x * MINIMAP_SCALE_FACTOR;
		line.y0 = game->player.y * MINIMAP_SCALE_FACTOR;
		line.x1 = game->rays.ray[i]->wall_intercept_x * MINIMAP_SCALE_FACTOR;
		line.y1 = game->rays.ray[i]->wall_intercept_y * MINIMAP_SCALE_FACTOR;
		line.color = RED;
		draw_line(&(game->frame), line);
		i++;
	}
}