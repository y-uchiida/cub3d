/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:13:44 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:28 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void		minimap_render(t_game *game)
{
	map_render(game);
	ray_render(game);
	put_sprite_marker(game);
	player_render(game);
	return ;
}
