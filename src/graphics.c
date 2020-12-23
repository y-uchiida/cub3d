/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:42:51 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/24 01:56:39 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		draw_rect(t_img *img, t_rect rect)
{
	int		i;
	int		j;

	i = rect.x0;
	while(i <= (rect.x0 + rect.width))
	{
		j = rect.y0;
		while(j <= (rect.y0 + rect.height))
		{
			image_put_pixel_color(img, i, j, rect.color);
			j++;
		}
		i++;
	}
}

void		draw_line(t_img *img, t_line line)
{
	int		i;
	int		longest_side_len;
	int		delta[2];
	float	increment[2];
	float	current[2];

	delta[TABINDEX_X] = line.x1 - line.x0;
	delta[TABINDEX_Y] = line.y1 - line.y0;
	longest_side_len = ft_abs(delta[TABINDEX_Y]);
	if (ft_abs(delta[TABINDEX_X]) >= ft_abs(delta[TABINDEX_Y]))
		longest_side_len = ft_abs(delta[TABINDEX_X]);
	increment[TABINDEX_X] = delta[TABINDEX_X] / (float)longest_side_len;
	increment[TABINDEX_Y] = delta[TABINDEX_Y] / (float)longest_side_len;
	current[TABINDEX_X] = line.x0;
	current[TABINDEX_Y] = line.y0;
	i = -1;
	while(++i < longest_side_len)
	{
		image_put_pixel_color(img,
			round(current[TABINDEX_X]), round(current[TABINDEX_Y]), line.color);
		current[TABINDEX_X] += increment[TABINDEX_X];
		current[TABINDEX_Y] += increment[TABINDEX_Y];
	}
}
