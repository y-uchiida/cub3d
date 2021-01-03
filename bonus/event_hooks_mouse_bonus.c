/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks_mouse_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:36:17 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:40 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int					mouse_move(int x, int y, t_game *game)
{
	t_mlx_window	*window;

	(void)y;
	window = &(game->mlx.window);
	if (window->mouse_pressed)
	{
		if (window->mouse_pos_x != -1)
			window->mouse_move_dist = x - window->mouse_pos_x;
		else
			window->mouse_move_dist = 0;
		window->mouse_pos_x = x;
	}
	return (EXIT_SUCCESS);
}

int					mouse_left_button_pressed(int button_num,
										int x, int y, t_game *game)
{
	(void)y;
	if (button_num == 1)
	{
		game->mlx.window.mouse_pressed = true;
		game->mlx.window.mouse_pos_x = x;
		game->mlx.window.mouse_move_dist = 0;
	}
	return (EXIT_SUCCESS);
}

int					mouse_left_button_released(int button_num,
										int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button_num == 1)
	{
		game->mlx.window.mouse_pressed = false;
		game->mlx.window.mouse_pos_x = -1;
		game->mlx.window.mouse_move_dist = 0;
	}
	return (EXIT_SUCCESS);
}
