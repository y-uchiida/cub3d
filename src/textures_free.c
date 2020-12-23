/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:44:05 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/23 17:11:51 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	textures_free(t_game *game)
{
	if (game->texture.wall_no.ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->texture.wall_no.ptr);
		game->texture.wall_no.ptr = NULL;
	}
	if (game->texture.wall_so.ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->texture.wall_so.ptr);
		game->texture.wall_so.ptr = NULL;
	}
	if (game->texture.wall_we.ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->texture.wall_we.ptr);
		game->texture.wall_we.ptr = NULL;
	}
	if (game->texture.wall_ea.ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->texture.wall_ea.ptr);
		game->texture.wall_ea.ptr = NULL;
	}
	if (game->texture.sprite.ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, game->texture.sprite.ptr);
		game->texture.sprite.ptr = NULL;
	}
}
