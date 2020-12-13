/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 05:19:14 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:40 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	char	*str;
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if ((substr = (char *)ft_calloc(1, sizeof(char) * 1)) == NULL)
			return (NULL);
		return (substr);
	}
	str = (char *)s;
	str = str + start;
	if (ft_strlen(str) < len)
		substr_len = ft_strlen(str);
	else
		substr_len = len;
	substr = (char *)malloc(sizeof(char) * substr_len + 1);
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, str, substr_len);
	substr[substr_len] = '\0';
	return (substr);
}
