/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_hair_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 05:34:05 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:32:57 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cross_hair_free(t_game *game)
{
	if (game->cross_hair->img->ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->cross_hair->img->ptr);
		game->cross_hair->img->ptr = NULL;
		game->cross_hair->img->data = NULL;
	}
	return ;
}
