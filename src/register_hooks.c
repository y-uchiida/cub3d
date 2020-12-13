/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:32:39 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 14:45:06 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	close_button_pressed(t_game *game)
{
	game->running = false;
	return (0);
}


static int	key_pressed(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		game->running = false;
	else if (keycode == XK_w)
		game->player.move_direction = +1;
	else if (keycode == XK_s)
		game->player.move_direction = -1;
	else if (keycode == XK_d)
		game->player.turn_direction = +1;
	else if (keycode == XK_a)
		game->player.turn_direction = -1;
	return (0);
}

static int	key_released(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_s)
		game->player.move_direction = 0;
	else if (keycode == XK_d || keycode == XK_a)
		game->player.turn_direction = 0;
	return (0);
}

static int	game_loop(t_game *game)
{
	game_data_update(game);
	render_image(game);
	return (0);
}

bool		register_hooks(t_game *game)
{
	mlx_hook(game->mlx.window.ptr, KeyPress, KeyPressMask, key_pressed, game);
	mlx_hook(game->mlx.window.ptr, KeyRelease, KeyReleaseMask,
		key_released, game);
	mlx_hook(game->mlx.window.ptr, DestroyNotify, StructureNotifyMask,
		close_button_pressed, game);
	mlx_loop_hook(game->mlx.window.ptr, game_loop, game);
	return (true);
}
