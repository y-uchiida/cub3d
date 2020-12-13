/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 03:22:09 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:09 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t src_len;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 <= size)
		ft_memcpy(dest, (void *)src, src_len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, (void *)src, size - 1);
		dest[size - 1] = '\0';
	}
	return (src_len);
}
