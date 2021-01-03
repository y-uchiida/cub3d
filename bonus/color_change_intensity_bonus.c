/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change_intensity_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 04:32:11 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:53:43 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	color_change_intensity(t_color *color, float factor)
{
	t_color t;
	t_color r;
	t_color g;
	t_color b;

	t = (*color & 0xff000000);
	r = (*color & 0x00ff0000) * factor;
	g = (*color & 0x0000ff00) * factor;
	b = (*color & 0x000000ff) * factor;
	*color = (t | (r & 0x00ff0000) | (g & 0x0000ff00) | (b & 0x000000ff));
}
