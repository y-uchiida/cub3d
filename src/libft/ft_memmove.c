/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:58:25 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:02:20 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_p;
	char	*src_p;
	char	*dest_end;
	char	*src_end;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_p = (char *)dest;
	src_p = (char *)src;
	if (dest_p < src_p)
		while (n--)
			*dest_p++ = *src_p++;
	else
	{
		dest_end = dest_p + (n - 1);
		src_end = src_p + (n - 1);
		while (n--)
			*dest_end-- = *src_end--;
	}
	return (dest);
}
