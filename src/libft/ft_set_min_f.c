/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_min_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:52:42 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 08:37:50 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_set_min_f(float num1, float num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}