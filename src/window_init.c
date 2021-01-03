/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:47:57 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 01:45:13 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool				window_init(t_game *game)
{
	game->mlx.window.ptr = mlx_new_window(game->mlx.ptr,
				game->mlx.window.width, game->mlx.window.height, "cub3D");
	game->mlx.window.mouse_pressed = false;
	game->mlx.window.mouse_pos_x = -1;
	return (true);
}
