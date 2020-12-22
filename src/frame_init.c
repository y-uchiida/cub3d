/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 03:44:13 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/23 05:00:43 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool				frame_init(t_game *game)
{
	t_img			*frame;
	t_mlx_window	window;

	frame = game->frame;
	window = game->mlx.window;
	frame->ptr = mlx_new_image(game->mlx.ptr, window.width, window.height);
	if (frame->ptr == NULL)
		return (put_errors(ERR_MLX_IMAGE_FAILD, "frame_init"));
	frame->data = mlx_get_data_addr(frame->ptr, &(frame->bpp),
									&(frame->size_line), &(frame->endian));
	return (true);
}