/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:09:52 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/25 15:35:12 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	where_is_ten(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == 10)
			return (i);
	}
	return (-1);
}

int	where_is_start(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != -1) // peut etre pb avec le \0
			return (i);
		i++;
	}
	return (0);
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
	j = where_is_ten(buf);
	if (j != -1)
	{
		cache = ft_substr(buf, where_is_start(buf), j + 1); // leaks
		while (j)
			buf[j--] = -1;
		return (cache);
	}
	while (1)
	{
		if (read(fd, buf, BUFFER_SIZE) <= 0)
			return (NULL); // free_all needed?
		if (!ft_strchr(buf, '\n'))
			cache = ft_strjoin(cache, buf); // leaks
		else
		{
			cache = ft_strjoin(cache, ft_substr(buf, where_is_start(buf), where_is_ten(buf) + 1)); // leaks
			j = where_is_ten(buf);
			while (j)
				buf[j--] = -1;
			return (cache);
		}
	}
	return (NULL);
}
