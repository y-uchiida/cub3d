/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 03:30:55 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:02:16 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_p;
	const char	*src_p;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_p = (char *)dest;
	src_p = (char *)src;
	while (n-- > 0)
	{
		*dest_p = *src_p;
		dest_p++;
		src_p++;
	}
	return (dest);
}
