/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put_pixel_color_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 04:03:14 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:36 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void		image_put_pixel_color(t_img *img, int x, int y, t_color color)
{
	char	*dest;

	dest = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(t_color *)dest = color;
	return ;
}
