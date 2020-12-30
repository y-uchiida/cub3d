/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_new_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:53:19 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/31 04:20:31 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool			sprite_new_item(t_game *game, int x, int y)
{
	t_sprite	*new_spr;
	t_sprite	*last;

	game->sprites.num += 1;
	if ((new_spr = (t_sprite *)ft_calloc(1, sizeof(t_sprite))) == NULL)
		return (put_errors(ERR_MALLOC_FAILED, "sprite_new_item"));
	new_spr->grid_x = x;
	new_spr->grid_y = y;
	new_spr->x = (float)((x + 0.5) * TILE_SIZE);
	new_spr->y = (float)((y + 0.5) * TILE_SIZE);
	new_spr->dist = FLT_MIN;
	new_spr->next = NULL;
	if (game->sprites.num == 1)
		game->sprites.sprite = new_spr;
	else
	{
		last = game->sprites.sprite;
		while (last->next != NULL)
			last = last->next;
		last->next = new_spr;
	}
	return (true);
}
