/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:44:05 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/20 00:33:38 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void free_each_tex(t_img *tex)
{
	if (tex->data != NULL)
	{
		free(tex->data);
		tex->data = NULL;
	}
	return ;
}

void	textures_free(t_game *game)
{
	if (game->texture.wall_no.data != NULL)
	{
		printf("noth: %p\n", game->texture.wall_no.data);
		free_each_tex(&(game->texture.wall_no));
		game->texture.wall_no.data = NULL;
	}
	if (game->texture.wall_so.data != NULL)
	{
		printf("south: %p\n", game->texture.wall_so.data);
		free_each_tex(&(game->texture.wall_so));
		game->texture.wall_so.data = NULL;
	}
	if (game->texture.wall_we.data != NULL)
	{
		printf("west: %p\n", game->texture.wall_we.data);
		free_each_tex(&(game->texture.wall_we));
		game->texture.wall_we.data = NULL;
	}
	if (game->texture.wall_ea.data != NULL)
	{
		printf("east: %p\n", game->texture.wall_ea.data);
		free_each_tex(&(game->texture.wall_ea));
		game->texture.wall_ea.data = NULL;
	}
	if (game->texture.sprite.data != NULL)
	{
		printf("sprite: %p\n", game->texture.sprite.data);
		free_each_tex(&(game->texture.sprite));
		game->texture.sprite.data = NULL;
	}
}