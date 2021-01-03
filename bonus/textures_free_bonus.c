/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:44:05 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:14 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	tex_free(t_game *game, t_img *tex)
{
	if (tex->ptr != NULL)
	{
		mlx_destroy_image(game->mlx.ptr, tex->ptr);
		tex->ptr = NULL;
		tex->data = NULL;
	}
}

void		textures_free(t_game *game)
{
	if (game->texture.wall_no.ptr != NULL)
		tex_free(game, &(game->texture.wall_no));
	if (game->texture.wall_so.ptr != NULL)
		tex_free(game, &(game->texture.wall_so));
	if (game->texture.wall_we.ptr != NULL)
		tex_free(game, &(game->texture.wall_we));
	if (game->texture.wall_ea.ptr != NULL)
		tex_free(game, &(game->texture.wall_ea));
	if (game->texture.sprite.ptr != NULL)
		tex_free(game, &(game->texture.sprite));
}
