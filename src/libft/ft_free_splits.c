/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 03:43:49 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/31 02:40:25 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_splits(char **splits)
{
	int		i;

	i = 0;
	while (splits[i] != NULL)
	{
		ft_free_and_set_null(splits[i]);
		i++;
	}
	ft_free_and_set_null(splits);
	return ;
}
