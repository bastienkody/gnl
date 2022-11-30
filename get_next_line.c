/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:09:52 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/30 14:07:33 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	readnl(int fd, char buf[])
{
	clr_buf(buf, -1, '\0');
	return (read(fd, buf, BUFFER_SIZE));
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

char	*finall(char *line, char buf[], int eof)
{
	if (eof < 0)
	{
		free(line);
		return (NULL);
	}
	clr_buf(buf, -1, '\0');
	return (line);
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
