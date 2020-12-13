/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:02:18 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:29 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	len;

	p = (char *)s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (p[len - 1] == (char)c)
			return (&p[len - 1]);
		len--;
	}
	if (c == '\0')
		return (&p[ft_strlen(s)]);
	else
		return (NULL);
}
