/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 04:45:13 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:01:26 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	char	buf[12];
	int		i;
	int		sign;

	if (n == 0)
		return (str = ft_strdup("0"));
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
	if ((str = ft_strdup(buf)) == NULL)
		return (str);
	return (str);
}
