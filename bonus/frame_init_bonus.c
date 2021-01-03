/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 03:44:13 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:39 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool				frame_init(t_game *game)
{
	t_mlx_window	win;

	win = game->mlx.window;
	game->frame.ptr = mlx_new_image(game->mlx.ptr, win.width, win.height);
	if (game->frame.ptr == NULL)
		return (put_errors(ERR_MLX_IMAGE_FAILD, "frame_init"));
	game->frame.data = mlx_get_data_addr(game->frame.ptr, &(game->frame.bpp),
							&(game->frame.size_line), &(game->frame.endian));
	game->frame.width = win.width;
	game->frame.height = win.height;
	return (true);
}
