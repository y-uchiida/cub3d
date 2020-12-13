/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 04:47:34 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:02:27 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	msk1;
	char	msk2;
	char	head;
	char	tail;

	if ((unsigned char)c <= 0x7F)
		write(fd, &c, 1);
	else
	{
		msk1 = 0b00111111;
		msk2 = 0b11000000;
		head = (((unsigned char)c & msk2) >> 6) | msk2;
		tail = ((unsigned char)c & msk1) | 0b10000000;
		write(fd, &head, 1);
		write(fd, &tail, 1);
	}
}
