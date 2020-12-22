/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 03:44:13 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/23 06:36:40 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool				frame_init(t_game *game)
{
	t_img			*frame;
	t_mlx_window	window;

	frame = game->frame;
	window = game->mlx.window;

	// void *test;
	// char *data;
	// void *mlx;
	// int tab[10];

	if (window.ptr == NULL || frame) {}


	printf("before mlx new image\n");
	printf("mlx.ptr: %p\n", game->mlx.ptr);
	printf("window_width: %d\n", game->mlx.window.width);
	printf("window_height: %d	\n", game->mlx.window.height);
	// frame->ptr = mlx_new_image(game->mlx.ptr, window.width, window.height);
	// mlx = mlx_init();
	// test = mlx_new_image(mlx, 1000, 1000);
	
	game->frame->ptr = mlx_new_image(game->mlx.ptr, 
				game->mlx.window.width, game->mlx.window.height);
	if (game->frame->ptr == NULL)
		return (put_errors(ERR_MLX_IMAGE_FAILD, "frame_init"));
	printf("before mlx get data addr\n");
	frame->data = mlx_get_data_addr(frame->ptr, &(frame->bpp),
									&(frame->size_line), &(frame->endian));

	// data = mlx_get_data_addr(test, &(tab[0]), &(tab[1]), &(tab[2]));

	// printf("data: %d\n", data[0]);
	printf("afert done.\n");
	return (true);
}