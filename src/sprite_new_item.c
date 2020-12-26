/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_new_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:53:19 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/26 22:40:06 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool			sprite_new_item(t_game *game, int x, int y)
{
	t_sprite	*new_spr;
	t_sprite	*list_ptr;

	game->sprites.num += 1;
	if ((new_spr = (t_sprite *)ft_calloc(sizeof(t_sprite), 1)) == NULL)
		return (put_errors(ERR_MALLOC_FAILED, "sprite_new_item"));
	new_spr->x = (float)(x + 0.5);
	new_spr->y = (float)(y + 0.5);
	new_spr->height = 200;
	new_spr->width = 200;
	new_spr->next = NULL;
	if (game->sprites.num == 1)
		game->sprites.sprite = (void *)new_spr;
	else
	{
		list_ptr = game->sprites.sprite;
		while (list_ptr->next != NULL)
			list_ptr = (t_sprite *)list_ptr->next;
		list_ptr->next = (void *)new_spr;
	}
	return (true);
}