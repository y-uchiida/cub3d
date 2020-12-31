/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:13:44 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/31 15:15:27 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		minimap_render(t_game *game)
{
	map_render(game);
	ray_render(game);
	put_sprite_marker(game);
	player_render(game);
	return ;
}
