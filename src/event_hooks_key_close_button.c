/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks_key_close_button.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:32:43 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 04:24:30 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			close_button_pressed(t_game *game)
{
	game->running = false;
	return (EXIT_SUCCESS);
}

int			key_pressed(int keycode, t_game *game)
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
	else if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		sprite_add_in_map(game);
	return (0);
}

int			key_released(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_s)
		game->player.move_direction = 0;
	if (keycode == XK_d || keycode == XK_a)
		game->player.move_direction = 0;
	else if (keycode == XK_Right || keycode == XK_Left)
		game->player.turn_direction = 0;
	return (0);
}
