/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:27:26 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/14 00:02:44 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool		put_errors(char *err)
{
	ft_putstr_fd(TEXT_RED, 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("-->", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd(TEXT_RESET, 2);
	ft_putstr_fd("\n", 2);
	return false;
}
