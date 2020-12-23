/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:47:57 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/23 11:26:20 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	window_init(t_game *game)
{
	game->mlx.window.ptr = mlx_new_window(game->mlx.ptr, 
				game->mlx.window.width, game->mlx.window.height, "cub3D");
	return (true);
}