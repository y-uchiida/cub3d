/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_hair_free_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 05:34:05 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:42 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
