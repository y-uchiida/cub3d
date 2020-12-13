/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 21:50:45 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:01:37 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*target;

	if (lst == NULL || del == NULL)
		return ;
	target = *lst;
	while (target != NULL)
	{
		next = target->next;
		ft_lstdelone(target, del);
		target = next;
	}
	free(lst);
	*lst = NULL;
}
