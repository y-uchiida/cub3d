/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:22:25 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:02:04 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *end;
	char *dest_c;
	char *src_c;

	dest_c = (char *)dest;
	src_c = (char *)src;
	end = (char *)ft_memchr(src, c, n);
	if (end != NULL)
	{
		while (src_c != end)
		{
			*dest_c = (char)*src_c;
			dest_c++;
			src_c++;
		}
		*dest_c = (char)*src_c;
		return (++dest_c);
	}
	ft_memcpy(dest_c, src, n);
	return (NULL);
}
