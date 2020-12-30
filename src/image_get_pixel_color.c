/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_get_pixel_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:39:15 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:30:38 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_color		image_get_pixel_color(int x, int y, t_img *img)
{
	char	*color_ptr;

	color_ptr = img->data + (y * img->size_line + x * (img->bpp / 8));
	return (*(t_color *)color_ptr);
}
