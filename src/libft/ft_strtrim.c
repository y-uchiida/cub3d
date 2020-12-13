/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 00:35:50 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:03:36 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isseparator(char t, char const *separators)
{
	char *p;

	p = (char *)separators;
	while (*p != '\0')
	{
		if (t == *p)
			return (1);
		p++;
	}
	return (0);
}

static size_t	separators_count_head(char const *str, char const *set)
{
	size_t	count;
	char	*p;

	count = 0;
	p = (char *)str;
	while (*p != '\0' && ft_isseparator(*p, set))
	{
		p++;
		count++;
	}
	return (count);
}

static size_t	separators_count_tail(char const *str, char const *set)
{
	size_t	count;
	char	*p;

	count = 0;
	p = (char *)str + ft_strlen(str) - 1;
	while (*p != '\0' && ft_isseparator(*p, set))
	{
		p--;
		count++;
	}
	return (count);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_str;
	size_t	head_index;
	size_t	tail_index;
	size_t	len;
	size_t	trimed_len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	tail_index = separators_count_tail(s1, set);
	if (len == tail_index)
		return (ft_strdup(""));
	head_index = separators_count_head(s1, set);
	trimed_len = len - head_index - tail_index;
	if ((trimed_str = (char *)malloc(sizeof(char) * trimed_len + 1)) == NULL)
		return (NULL);
	ft_strlcpy(trimed_str, s1 + head_index, trimed_len + 1);
	return (trimed_str);
}
