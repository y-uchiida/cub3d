/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:51:35 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:07:47 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_check_extension(char *str, char *ext)
{
	int i;
	int	str_len;
	int	ext_len;

	str_len = ft_strlen(str);
	ext_len = ft_strlen(ext);
	if (str_len < ext_len)
		return (false);
	i = 1;
	while (i <= ext_len)
	{
		if (str[str_len - i] != ext[ext_len - i])
			return (false);
		i++;
	}
	if (str[str_len - i] != '.')
		return (false);
	return (true);
}
