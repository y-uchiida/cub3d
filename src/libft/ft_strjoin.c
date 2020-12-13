/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:07:31 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:01 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((joined = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	joined[len] = '\0';
	ft_memmove(joined, (void *)s1, ft_strlen(s1));
	ft_memmove(&joined[ft_strlen(s1)], (void *)s2, ft_strlen(s2));
	joined[ft_strlen(joined)] = '\0';
	return (joined);
}
