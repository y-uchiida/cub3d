/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_trgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 01:29:13 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/29 16:39:18 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_color		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int			get_t(t_color trgb)
{
	return ((trgb & (0xff000000)) >> 24);
}

int			get_r(t_color trgb)
{
	return ((trgb & (0x00ff0000)) >> 16);
}

int			get_g(t_color trgb)
{
	return ((trgb & (0x0000ff00)) >> 8);
}

int			get_b(t_color trgb)
{
	return (trgb & 0x000000ff);
}