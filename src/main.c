/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:06:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 11:25:01 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool			setup(t_game *game)
{
	game->running = true;
	player_init(game);
	frame_init(game);
	ray_init(game);
	minimap_init(game);
	mlx_do_key_autorepeaton(game->mlx.ptr);
	mlx_do_sync(game->mlx.ptr);
	return (true);
}

bool				game_init(t_game *game)
{
	if ((game->mlx.ptr = mlx_init()) == NULL)
		return (put_errors(ERR_MLX_INIT_FAILURE, "game_init"));
	mlx_get_screen_size(game->mlx.ptr,
				&game->mlx.window.max_width, &game->mlx.window.max_height);
	game->mlx.window.ptr = NULL;
	game->mlx.window.width = INT_MIN;
	game->mlx.window.height = INT_MIN;
	game->fov_angle = (60 * (PI / 180));
	game->fov_occupancy = game->fov_angle / (360 * (PI / 180));
	game->map.ceil_color = NONE;
	game->map.floor_color = NONE;
	game->player.x = FLT_MIN;
	game->player.y = FLT_MIN;
	game->player.initial_x = INT_MIN;
	game->player.initial_y = INT_MIN;
	game->sprites.num = 0;
	game->sprites.sprite = NULL;
	return (true);
}

int					main(int argc, char *argv[])
{
	static t_game	game;

	if (game_init(&game) == false)
		return (EXIT_FAILURE);
	if (argc >= 2)
	{
		if (import_cub_file(&game, argv[1]) == false)
			return (EXIT_FAILURE);
	}
	else
		return (put_errors(ERR_NO_ARG, "main"));
	setup(&game);
	if ((argc == 3) && (ft_strncmp(argv[2], "--save", 6) == 0))
	{
		if (screenshot_save(&game) == false)
			game_exit(&game);
	}
	else
	{
		window_init(&game);
		register_hooks(&game);
		mlx_loop(game.mlx.ptr);
	}
	return (EXIT_SUCCESS);
}
