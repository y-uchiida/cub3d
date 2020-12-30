/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:47:57 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 11:08:52 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool				window_init(t_game *game)
{
	t_mlx_window	*window;

	window = &(game->mlx.window);
	window->dist_prj_plane = ((window->width / 2) / tan(game->fov_angle / 2));
	game->mlx.window.ptr = mlx_new_window(game->mlx.ptr,
				game->mlx.window.width, game->mlx.window.height, "cub3D");
	return (true);
}
