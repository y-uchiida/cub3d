/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 04:34:04 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:59:04 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_splits(char **splits, size_t i)
{
	if (i == 0)
		free(splits);
	else
	{
		while (i)
		{
			free(splits[i]);
			i--;
		}
		free(splits);
	}
	return (NULL);
}

static size_t	count_words(char const *src, char c)
{
	size_t	count;
	char	*p;

	count = 0;
	p = (char *)src;
	while (*p != '\0')
	{
		if (p == src && *p != c)
			count++;
		else if (*p == c && *(p + 1) != c && *(p + 1) != '\0')
			count++;
		p++;
	}
	return (count);
}

char			**ft_split(const char *s, char c)
{
	char		**splits;
	char		*w_head;
	char		*w_tail;
	size_t		count;
	size_t		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	w_head = (char *)s;
	count = count_words(w_head, c);
	splits = ft_calloc(count + 1, sizeof(char *));
	while (*w_head != '\0' && splits != NULL)
	{
		if (!(w_tail = ft_strchr(w_head, c)))
			w_tail = &w_head[ft_strlen(w_head)];
		if (w_tail - w_head > 0)
		{
			if ((splits[i] = ft_substr(w_head, 0, w_tail - w_head)) == NULL)
				return (free_splits(splits, i));
			i++;
		}
		w_head = (w_tail - w_head > 0) ? w_tail : w_head + 1;
	}
	return (splits);
}
