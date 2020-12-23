/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:38:59 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/20 19:18:22 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		player_new_position(t_player *p, float *new_x, float *new_y)
{
	if (p->move_direction == 4)
	{
		*new_x = p->x + cos(p->rotation_angle) * p->move_speed;
		*new_y = p->y + sin(p->rotation_angle) * p->move_speed;
	}
	else if (p->move_direction == 2)
	{
		*new_x = p->x - cos(p->rotation_angle) * p->move_speed;
		*new_y = p->y - sin(p->rotation_angle) * p->move_speed;
	}
	else if (p->move_direction == 1)
	{
		*new_x = p->x + cos(p->rotation_angle) * p->move_speed;
		*new_y = p->y - sin(p->rotation_angle) * p->move_speed;
	}
	else if (p->move_direction == 3)
	{
		*new_x = p->x - cos(p->rotation_angle) * p->move_speed;
		*new_y = p->y + sin(p->rotation_angle) * p->move_speed;
	}
}

void			player_move(t_game *game)
{
	float		new_player_x;
	float		new_player_y;
	t_player	*p;
	t_map		*map;

	p = &(game->player);
	map = &(game->map);
	p->rotation_angle += p->turn_direction * p->turn_speed;
	if (p->move_direction != 0)
	{
		player_new_position(p, &new_player_x, &new_player_y);
		if (map_has_wall_at( new_player_x, new_player_y, map) != true)
		{
			p->x = new_player_x;
			p->y = new_player_y;
		}
	}
	return ;
}
