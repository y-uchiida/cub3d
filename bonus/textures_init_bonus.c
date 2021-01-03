/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:39:43 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:13 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void		textures_init(t_game *game)
{
	game->texture.wall_no.ptr = NULL;
	game->texture.wall_so.ptr = NULL;
	game->texture.wall_ea.ptr = NULL;
	game->texture.wall_we.ptr = NULL;
	game->texture.sprite.ptr = NULL;
}
