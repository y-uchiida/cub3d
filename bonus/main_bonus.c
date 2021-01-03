/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:06:43 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:33 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static bool			setup(t_game *game)
{
	game->running = true;
	game->mlx.window.dist_prj_plane =
		((game->mlx.window.width / 2) / tan(game->fov_angle / 2));
	player_init(game);
	frame_init(game);
	ray_init(game);
	minimap_init(game);
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
	game->map.rows = 0;
	game->map.cols = 0;
	textures_init(game);
	game->player.x = FLT_MIN;
	game->player.y = FLT_MIN;
	game->player.initial_x = INT_MIN;
	game->player.initial_y = INT_MIN;
	game->sprites.num = 0;
	game->sprites.sprite = NULL;
	return (true);
}

static bool			inspect_args(t_game *game, int argc, char **argv)
{
	int				arg_len;

	if (argc > 3)
		return (put_errors(ERR_TO_MUCH_ARGS, "inspect_args"));
	arg_len = ft_strlen(argv[2]);
	if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0 && arg_len == 6)
		return (screenshot_save(game));
	else
		return (put_errors(ERR_INVALID_SECOND_ARG, "inspect_args"));
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
	if (argc >= 3)
	{
		if (inspect_args(&game, argc, argv) == false)
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
