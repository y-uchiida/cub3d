/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 03:43:49 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/14 03:44:11 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_splits(char **splits)
{
	char	**ptr;

	ptr = splits;
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	free(splits);
	splits = NULL;
	return ;
}
