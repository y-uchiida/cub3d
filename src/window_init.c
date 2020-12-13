/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:47:57 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/14 00:16:37 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	window_init(t_game *game)
{
	int		w;
	int		h;

	game->mlx.window.height = -1;
	w = game->mlx.window.width;
	h = game->mlx.window.height;

	game->mlx.ptr = mlx_init();
	game->mlx.window.ptr = mlx_new_window(game->mlx.ptr, w, h, "cub3D");
	return (true);
}