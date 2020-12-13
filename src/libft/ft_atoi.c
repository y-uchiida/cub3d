/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:44:45 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 21:59:56 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	num;
	char			*p;

	p = (char *)nptr;
	while ((9 <= *p && *p <= 13) || *p == 32)
		p++;
	sign = 1;
	if (*p == '-' || *p == '+')
	{
		sign = (*p == '-') ? -1 : 1;
		p++;
	}
	num = 0;
	while (ft_isdigit(*p))
	{
		num = (unsigned long)(num * 10 + (*p - '0'));
		p++;
	}
	if (sign > 0 && num > LONG_MAX)
		return (-1);
	else if (sign < 0 && num > (unsigned long)(LONG_MIN))
		return (0);
	return (num * sign);
}
