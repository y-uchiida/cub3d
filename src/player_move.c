/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:38:59 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 04:16:01 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		move_strafe(t_player *p, float *new)
{
	float		move_x;
	float		move_y;

	move_x = (cos(p->rotation_angle - (PI / 2)) * p->move_speed);
	move_y = (sin(p->rotation_angle - (PI / 2)) * p->move_speed);
	if (p->move_direction == 1)
	{
		new[TABINDEX_X] = p->x - move_x;
		new[TABINDEX_Y] = p->y - move_y;
	}
	else
	{
		new[TABINDEX_X] = p->x + move_x;
		new[TABINDEX_Y] = p->y + move_y;
	}
}

static void		player_new_position(t_player *p, float *new)
{
	if (p->move_direction == 4)
	{
		new[TABINDEX_X] = p->x + (cos(p->rotation_angle) * p->move_speed);
		new[TABINDEX_Y] = p->y + (sin(p->rotation_angle) * p->move_speed);
	}
	else if (p->move_direction == 2)
	{
		new[TABINDEX_X] = p->x - (cos(p->rotation_angle) * p->move_speed);
		new[TABINDEX_Y] = p->y - (sin(p->rotation_angle) * p->move_speed);
	}
	else if (p->move_direction == 1 || p->move_direction == 3)
		move_strafe(p, new);
}

void			player_move(t_game *game)
{
	float		new[2];
	t_player	*p;
	t_sprite	*spr;
	t_map		*map;

	p = &(game->player);
	spr = game->sprites.sprite;
	while (spr->next != NULL)
		spr = spr->next;
	map = &(game->map);
	p->rotation_angle += p->turn_direction * p->turn_speed;
	p->rotation_angle += game->mlx.window.mouse_move_dist * p->turn_speed;
	normalize_angle(&(p->rotation_angle));
	if (p->move_direction != 0)
	{
		player_new_position(p, new);
		if (map_has_wall_at(new[TABINDEX_X], new[TABINDEX_Y], map) != true &&
			distance_between_points(new[TABINDEX_X], new[TABINDEX_Y],
														spr->x, spr->y) > 5.0)
		{
			p->x = new[TABINDEX_X];
			p->y = new[TABINDEX_Y];
		}
	}
	return ;
}
