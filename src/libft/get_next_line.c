/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:49:24 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 22:09:08 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		set_current_line(char **line, char **remain, int read_len)
{
	char		*nl_p;
	char		*next;

	nl_p = ft_strchr(*remain, '\n');
	if (nl_p != NULL)
	{
		*nl_p = '\0';
		if ((*line = ft_strdup(*remain)) == NULL)
			return (-1);
		if ((next = ft_strdup(nl_p + 1)) == NULL)
			return (-1);
		free(*remain);
		*remain = next;
		return (1);
	}
	else if (nl_p == NULL && (read_len < BUFFER_SIZE))
	{
		if ((*line = ft_strdup(*remain)) == NULL)
			return (-1);
		free(*remain);
		*remain = NULL;
		return (0);
	}
	else
		return (-2);
}

static int		add_new_buf(char **remain, char *buffer, int read_len)
{
	char		*joined;

	buffer[read_len] = '\0';
	if (*remain == NULL)
	{
		if ((*remain = ft_strdup(buffer)) == NULL)
			return (-1);
	}
	else
	{
		if ((joined = ft_strjoin(*remain, buffer)) == NULL)
			return (-1);
		free(*remain);
		*remain = joined;
	}
	return (0);
}

static int		read_buf(int fd, char **line, char **remain, char *buffer)
{
	int			read_len;

	if ((read_len = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (-1);
	if (read_len > 0)
	{
		if (add_new_buf(remain, buffer, read_len) == -1)
			return (-1);
	}
	if (*remain == NULL)
	{
		if ((*line = ft_strdup("")) == NULL)
			return (-1);
		return (0);
	}
	return (set_current_line(line, remain, read_len));
}

int				get_next_line(int fd, char **line)
{
	static char	*remains[FOPEN_MAX];
	int			rtn;
	char		*buffer;

	if (line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (fd < 0 || (buffer = malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	while ((rtn = read_buf(fd, line, &remains[fd], buffer)) != -1)
	{
		if (rtn == 0)
			free(remains[fd]);
		if (rtn >= 0)
		{
			free(buffer);
			return (rtn);
		}
	}
	if (remains[fd])
		free(remains[fd]);
	remains[fd] = NULL;
	if (buffer)
		free(buffer);
	return (-1);
}
