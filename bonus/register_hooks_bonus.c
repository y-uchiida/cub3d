/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:32:39 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:20 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int		game_loop(t_game *game)
{
	game_data_update(game);
	render_fov(game);
	sprite_render(game);
	minimap_render(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.window.ptr,
				game->frame.ptr, 0, 0);
	return (EXIT_SUCCESS);
}

bool			register_hooks(t_game *game)
{
	void	*window_ptr;

	window_ptr = game->mlx.window.ptr;
	mlx_do_key_autorepeaton(game->mlx.ptr);
	mlx_do_sync(game->mlx.ptr);
	mlx_hook(window_ptr, KeyPress, KeyPressMask, key_pressed, game);
	mlx_hook(window_ptr, KeyRelease, KeyReleaseMask, key_released, game);
	mlx_hook(window_ptr, MotionNotify, PointerMotionMask, mouse_move, game);
	mlx_hook(window_ptr, ButtonPress, ButtonPressMask,
										mouse_left_button_pressed, game);
	mlx_hook(window_ptr, ButtonRelease, ButtonReleaseMask,
										mouse_left_button_released, game);
	mlx_hook(window_ptr, ClientMessage, StructureNotifyMask,
											close_button_pressed, game);
	mlx_loop_hook(game->mlx.ptr, game_loop, game);
	return (true);
}
