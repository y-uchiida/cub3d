/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 04:50:06 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:19 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	size_t			str_len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if ((p = (char *)malloc(sizeof(char) * str_len + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < str_len)
		p[i] = f(i, s[i]);
	p[i] = '\0';
	return (p);
}
