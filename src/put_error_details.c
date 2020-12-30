/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_details.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 20:17:54 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:45:11 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		put_error_details(char *func_name)
{
	ft_putstr_fd(TEXT_RED, 2);
	ft_putstr_fd("Error has occured in function ", 2);
	perror(func_name);
	ft_putstr_fd(TEXT_RESET, 2);
	return ;
}
