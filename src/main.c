/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:06:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/19 18:35:07 by yoguchi          ###   ########.fr       */
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

	/* struct datas show: */
	printf("mlx window\n");
	printf("  - width: %d\n", game->mlx.window.width);
	printf("  - height: %d\n", game->mlx.window.height);

	printf("mlx map\n");
	printf("  - ceil color: %d, %d, %d\n",
		get_r(game->map.ceil_color),
		get_g(game->map.ceil_color),
		get_b(game->map.ceil_color));

	printf("  - floor color: %d, %d, %d\n",
		get_r(game->map.floor_color),
		get_g(game->map.floor_color),
		get_b(game->map.floor_color));

	printf(" - textures\n");
	printf(" - wall_no : %p\n", &game->texture.wall_no);
	printf(" - wall_no.data : %p\n", game->texture.wall_no.data);
	printf(" - wall_no.data int: %d\n", *(game->texture.wall_no.data));
	printf(" - wall_no.width : %d\n", game->texture.wall_no.width);

	printf(" - wall_so: %p\n", &game->texture.wall_so);
	printf(" - wall_so.data: %p\n", game->texture.wall_so.data);
	printf(" - wall_so.data int: %d\n", *(game->texture.wall_so.data));
	printf(" - wall_so.width : %d\n", game->texture.wall_so.width);

	printf(" - wall_ea : %p\n", &game->texture.wall_ea);
	printf(" - wall_ea.data : %p\n", game->texture.wall_ea.data);
	printf(" - wall_ea.data int: %d\n", *(game->texture.wall_ea.data));
	printf(" - wall_ea.width : %d\n", game->texture.wall_ea.width);

	printf(" - wall_we : %p\n", &game->texture.wall_we);
	printf(" - wall_we.data : %p\n", game->texture.wall_we.data);
	printf(" - wall_we.data int: %d\n", *(game->texture.wall_we.data));
	printf(" - wall_we.width : %d\n", game->texture.wall_we.width);

	printf(" - sprite    : %p\n", &game->texture.sprite);
	printf(" - sprite.data    : %p\n", game->texture.sprite.data);
	printf(" - sprite.data int: %d\n", *(game->texture.sprite.data));
	printf(" - sprite.width : %d\n", game->texture.sprite.width);

	printf("\n");

	printf("map field\n");
	int i = 0;
	while(game->map.map[i] != NULL)
	{
		printf("[%03d]%s\n", i, game->map.map[i]);
		i++;
	}

	printf ("\n");

	printf("player\n");
	printf(" - x: %f\n", game->player.x);
	printf(" - y: %f\n", game->player.y);
	printf(" - initial_x: %d\n", game->player.initial_x);
	printf(" - initial_y: %d\n", game->player.initial_y);
	printf(" - rotation_angle: %f\n", game->player.rotation_angle);
	printf(" - move_speed: %f\n", game->player.move_speed);
	printf(" - turn_speed: %f\n", game->player.turn_speed);
	printf(" - move_redection: %d\n", game->player.move_direction);
	printf(" - turn_direction: %d\n", game->player.turn_direction);
	
	printf ("\n");

	printf("data checks end.\n");

	return (true);
}

bool		game_init(t_game *game)
{
	if ((game->mlx.ptr = mlx_init()) == NULL)
		return (put_errors(ERR_MLX_INIT_FAILURE, "game_init"));
	mlx_get_screen_size(game->mlx.ptr,
				&game->mlx.window.max_width, &game->mlx.window.max_height);
	game->mlx.window.width = INT_MIN;
	game->mlx.window.height = INT_MIN;
	game->map.ceil_color = NONE;
	game->map.floor_color = NONE;
	game->player.x = FLT_MIN;
	game->player.y = FLT_MIN;
	game->player.initial_x = INT_MIN;
	game->player.initial_y = INT_MIN;
	return (true);
}

int			main(int argc, char *argv[])
{
	static t_game game;

	if (game_init(&game) == false)
		return (EXIT_FAILURE);
	if (argc >= 2)
	{
		if (import_cub_file(&game, argv[1]) == false)
			return (EXIT_FAILURE);
	}
	else
	{
		put_errors(ERR_NO_ARG, "main");
		return (EXIT_FAILURE);
	}
	setup(&game);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) == 0)) /* 画像出力する */
	{}
	mlx_loop(game.mlx.ptr);

	return (EXIT_SUCCESS);
}
