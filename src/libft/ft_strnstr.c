/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:49:44 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:25 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	n;
	size_t	i;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (!*little)
		return ((char *)big);
	n = 0;
	while (big[n] != '\0' && n < len)
	{
		if (big[n] == little[0])
		{
			i = 1;
			while (little[i] != '\0'
				&& (n + i < len)
				&& big[n + i] == little[i])
				i++;
			if (little[i] == '\0')
				return ((char *)&big[n]);
		}
		n++;
	}
	return (NULL);
}
