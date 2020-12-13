/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 06:19:53 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:05 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t concat_len;
	size_t dest_len;

	dest_len = ft_strlen(dest);
	concat_len = ft_strlen(src) + dest_len;
	if (dest_len >= size)
		return (size + ft_strlen(src));
	else
	{
		i = 0;
		while ((i + dest_len < size - 1) && (src[i] != '\0'))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	return (concat_len);
}
