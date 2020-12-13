/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:06:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/14 00:29:43 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool setup(t_game *game)
{
	game->running = true;
	window_init(game);
	player_init(game);
	ray_init(game);
	register_hooks(game);
	return (true);
}

void		game_init(t_game *game)
{
	game->mlx.window.width = INT_MIN;
	game->mlx.window.height = INT_MIN;
	game->map.ceil_color = NONE;
	game->map.floor_color = NONE;
}

int			main(int argc, char *argv[])
{
	static t_game game;

	game_init(&game);
	if (argc >= 2)
	{
		if (import_cub_file(&game, argv[1]) == false)
			return (EXIT_FAILURE);
	}
	else
	{
		put_errors(ERR_NO_ARG);
		return (EXIT_FAILURE);
	}
	setup(&game);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) == 0)) /* 画像出力する */
	{}

	mlx_loop(game.mlx.ptr);

	return (EXIT_SUCCESS);
}
