/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 03:06:02 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/27 03:08:40 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	frame_free(t_game *game)
{
	if (game->frame.ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->frame.ptr);
		game->frame.ptr = NULL;
		game->frame.data = NULL;
	}
}
