/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:52:42 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/19 17:56:02 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_set_min(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}