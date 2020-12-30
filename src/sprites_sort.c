/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:08:01 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 11:07:23 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		sprites_swap(t_game *game, t_sprite *prev, t_sprite *compare)
{
	t_sprite	*next;

	next = compare->next;
	compare->next = next->next;
	next->next = compare;
	if (prev == NULL)
		game->sprites.sprite = next;
	else
		prev->next = next;
}

void			sprites_sort(t_game *game)
{
	t_sprite	*prev;
	t_sprite	*sprite;
	t_sprite	*compare;

	prev = NULL;
	sprite = game->sprites.sprite;
	while (sprite != NULL)
	{
		compare = sprite;
		while (compare != NULL)
		{
			if (compare->next != NULL && compare->dist < compare->next->dist)
			{
				sprites_swap(game, prev, compare);
				prev = compare;
				compare = compare->next;
			}
			else
				break ;
		}
		prev = sprite;
		sprite = sprite->next;
	}
}
