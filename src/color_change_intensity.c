/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change_intensity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 04:32:11 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:12:32 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
