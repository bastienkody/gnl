/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:09:52 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/29 19:55:27 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	idx_of(char *buf, char c)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == c)
			return (i);
	}
	return (-1);
}

int	itrig(char *buf)
{
	int	i;

	i = 0;
	if (*buf != -1)
		return (i);
	while (buf[i] == TRIG)
		i++;
	return (i);
}

char	*init(char **line, char buf[], int *eof)
{
	buf[BUFFER_SIZE] = '\0';
	*eof = 1;
	*line = malloc(sizeof(char));
	if (!*line)
		return (NULL);
	**line = '\0';
	return (*line);
}

void	clr_buf(char buf[], int j, char val)
{
	int	i;

	i = -1;
	if (j < 0)
	{
		while (++i < BUFFER_SIZE)
			buf[i] = val;
		return ;
	}
	while (++i <= j)
		buf[i] = val;
	return ;
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line;
	int				j;
	int				eof;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !init(&line, buf, &eof))
		return (NULL);
	while (eof > 0)
	{
		j = idx_of(buf, '\n');
		if (j != -1)
		{
			line = strj(line, subs(buf, itrig(buf), j + 1 - itrig(buf)));
			clr_buf(buf, j, TRIG);
			return (line);
		}
		line = strj(line, subs(buf, itrig(buf), strle(buf) - itrig(buf)));
		if (!line)
			return (NULL);
		eof = readnl(fd, buf);
	}
	if (eof < 0)
		return (finall(line, buf, eof));
	return (finall(line, buf, eof));
}
