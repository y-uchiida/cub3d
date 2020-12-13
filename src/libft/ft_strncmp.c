/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 23:36:59 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:22 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	len_s1;
	size_t	len_s2;

	if (n == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = (len_s1 < len_s2) ? len_s1 + 1 : len_s2 + 1;
	len = (len < n) ? len : n;
	return (ft_memcmp(s1, s2, len));
}
