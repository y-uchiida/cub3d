/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 04:06:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/16 23:37:39 by yoguchi          ###   ########.fr       */
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
	printf(" - noth_wall : %p\n", &game->texture.noth_wall);
	printf(" - noth_wall.data : %p\n", game->texture.noth_wall.data);
	printf(" - noth_wall.data val: %.10s\n", game->texture.noth_wall.data);
	printf(" - noth_wall.data int: %d\n", *(game->texture.noth_wall.data));
	printf(" - noth_wall.width : %d\n", game->texture.noth_wall.width);

	printf(" - south_wall: %p\n", &game->texture.south_wall);
	printf(" - south_wall.data: %p\n", game->texture.south_wall.data);
	printf(" - south_wall.data val: %.10s\n", game->texture.south_wall.data);
	printf(" - south_wall.data int: %d\n", *(game->texture.south_wall.data));
	printf(" - south_wall.width : %d\n", game->texture.south_wall.width);

	printf(" - east_wall : %p\n", &game->texture.east_wall);
	printf(" - east_wall.data : %p\n", game->texture.east_wall.data);
	printf(" - east_wall.data val: %.10s\n", game->texture.east_wall.data);
	printf(" - east_wall.data int: %d\n", *(game->texture.east_wall.data));
	printf(" - east_wall.width : %d\n", game->texture.east_wall.width);

	printf(" - west_wall : %p\n", &game->texture.west_wall);
	printf(" - west_wall.data : %p\n", game->texture.west_wall.data);
	printf(" - west_wall.data val: %.10s\n", game->texture.west_wall.data);
	printf(" - west_wall.data int: %d\n", *(game->texture.west_wall.data));
	printf(" - west_wall.width : %d\n", game->texture.west_wall.width);

	printf(" - sprite    : %p\n", &game->texture.sprite);
	printf(" - sprite.data    : %p\n", game->texture.sprite.data);
	printf(" - sprite.data val: %.10s\n", game->texture.sprite.data);
	printf(" - sprite.data int: %d\n", *(game->texture.sprite.data));
	printf(" - sprite.width : %d\n", game->texture.sprite.width);

	return (true);
}

bool		game_init(t_game *game)
{
	if ((game->mlx.ptr = mlx_init()) == NULL)
		return (put_errors(ERR_MLX_INIT_FAILURE));
	mlx_get_screen_size(game->mlx.ptr,
				&game->mlx.window.max_width, &game->mlx.window.max_height);
	game->mlx.window.width = INT_MIN;
	game->mlx.window.height = INT_MIN;
	game->map.ceil_color = NONE;
	game->map.floor_color = NONE;
	game->player.x = FLT_MIN;
	game->player.y = FLT_MIN;
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
		put_errors(ERR_NO_ARG);
		return (EXIT_FAILURE);
	}
	setup(&game);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) == 0)) /* 画像出力する */
	{}
	mlx_loop(game.mlx.ptr);

	return (EXIT_SUCCESS);
}
