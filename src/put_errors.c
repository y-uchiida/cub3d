/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:27:26 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 10:45:29 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool		put_errors(char *err, char *func_name)
{
	ft_putstr_fd(TEXT_RED, 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("--> ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Error has occured in function ", 2);
	perror(func_name);
	ft_putstr_fd(TEXT_RESET, 2);
	ft_putstr_fd("\n", 2);
	return (false);
}
