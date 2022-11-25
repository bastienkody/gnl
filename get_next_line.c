/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:09:52 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/25 19:12:22 by bguillau         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*cache;
	int				j;

	if (fd < 0)
		return (NULL);
	cache = "";
	buf[BUFFER_SIZE] = '\0';
	j = idx_of(buf, '\n');
	if (j != -1)
	{
		cache = ft_substr(buf, idx_of(buf, TRIG), j + 1); // leaks
		while (j > -1)
			buf[j--] = TRIG;
		return (cache);
	}
	else
		cache = ft_strjoin(cache, ft_substr(buf, idx_of(buf, TRIG), ft_strlen(buf))); // leaks
	while (1)
	{
		if (read(fd, buf, BUFFER_SIZE) < 0)
			return (NULL); // free_all needed?
		if (!ft_strchr(buf, '\n'))
			cache = ft_strjoin(cache, buf); // leaks
		else
		{
			cache = ft_strjoin(cache, ft_substr(buf, idx_of(buf, TRIG), idx_of(buf, '\n') + 1)); // leaks
			j = idx_of(buf, '\n');
			while (j > -1)
				buf[j--] = TRIG;
			return (cache);
		}
	}
	return (NULL);
}
