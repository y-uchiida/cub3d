/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:10:55 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:21 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

bool		ray_init(t_game *game)
{
	int		strip_id;

	game->rays.num = game->mlx.window.width;
	game->rays.ray = (t_ray **)ft_calloc(sizeof(t_ray *), game->rays.num);
	if (game->rays.ray == NULL)
		return (put_errors(ERR_MALLOC_FAILED, "ray_init"));
	strip_id = 0;
	while (strip_id < game->rays.num)
	{
		game->rays.ray[strip_id] = (t_ray *)ft_calloc(sizeof(t_ray), 1);
		if (&(game->rays.ray[strip_id]) == NULL)
		{
			ray_free(game);
			return (put_errors(ERR_MALLOC_FAILED, "ray_init"));
		}
		strip_id++;
	}
	return (true);
}
