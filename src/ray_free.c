/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 03:14:07 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:51:00 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ray_free(t_game *game)
{
	int	strip_id;

	strip_id = 0;
	while (strip_id < game->rays.num)
	{
		if (game->rays.ray[strip_id] == NULL)
			break ;
		free(game->rays.ray[strip_id]);
		strip_id++;
	}
	return ;
}
