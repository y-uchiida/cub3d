/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:32:39 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/31 04:08:22 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		close_button_pressed(t_game *game)
{
	game->running = false;
	return (EXIT_SUCCESS);
}

static int		key_pressed(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		game->running = false;
	else if (keycode == XK_w)
		game->player.move_direction = 4;
	else if (keycode == XK_s)
		game->player.move_direction = 2;
	else if (keycode == XK_d)
		game->player.move_direction = 1;
	else if (keycode == XK_a)
		game->player.move_direction = 3;
	else if (keycode == XK_Right)
		game->player.turn_direction = +1;
	else if (keycode == XK_Left)
		game->player.turn_direction = -1;
	return (0);
}

static int		key_released(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_s)
		game->player.move_direction = 0;
	if (keycode == XK_d || keycode == XK_a)
		game->player.move_direction = 0;
	else if (keycode == XK_Right || keycode == XK_Left)
		game->player.turn_direction = 0;
	return (0);
}

static int		game_loop(t_game *game)
{
	game_data_update(game);
	render_fov(game);
	sprite_render(game);
	map_render(game);
	ray_render(game);
	put_sprite_marker(game);
	player_render(game);
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
	mlx_hook(window_ptr, ClientMessage, StructureNotifyMask,
											close_button_pressed, game);
	mlx_loop_hook(game->mlx.ptr, game_loop, game);
	return (true);
}
