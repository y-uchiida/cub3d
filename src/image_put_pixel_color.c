/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put_pixel_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 04:03:14 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/23 04:52:49 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		image_put_pixel_color(t_img *img, int x, int y, t_color color)
{
	char	*dest;

    dest = img->data + (y * img->size_line + x * (img->bpp / 8));
    *(unsigned int *)dest = color;
	return ;
}