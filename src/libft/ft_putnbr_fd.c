/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 05:01:00 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:02:38 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	buf[12];
	int		i;
	int		sign;

	if (n == 0)
	{
		return (ft_putchar_fd('0', fd));
	}
	else
	{
		ft_bzero(buf, 12);
		sign = n;
		i = 0;
		while (n != 0)
		{
			buf[i++] = ft_abs(n % 10) + '0';
			n = n / 10;
		}
		if (sign < 0)
			buf[i++] = '-';
		ft_strrev(buf);
		ft_putstr_fd(buf, fd);
	}
}
