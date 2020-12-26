/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:12:00 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/26 21:53:31 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			sprites_free(t_game *game)
{
	t_sprite	*ptr;
	t_sprite	*tmp;

	ptr = game->sprites.sprite;
	while (ptr != NULL)
	{
		tmp = (t_sprite *)ptr->next;
		free(ptr);
		ptr = NULL;
		ptr = tmp;
	}
	game->sprites.num = 0;
}