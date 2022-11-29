/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:53 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/29 18:44:34 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	readnl(int fd, char buf[])
{
	clr_buf(buf, -1, '\0');
	return (read(fd, buf, BUFFER_SIZE));
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

int	strle(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*strj(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc((strle(s1) + strle(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
			res[++j] = s1[i];
	i = -1;
	while (s2[++i])
			res[++j] = s2[i];
	res[++j] = '\0';
	free(s1);
	free(s2);
	return (res);
}

char	*subs(char *s, int start, int len)
{
	char	*res;
	int		i;
	int		new_len;

	if (len > strle(s) - start)
		new_len = strle(s) - start;
	else
		new_len = len;
	res = malloc((new_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (s[++i + start] && len--)
		res[i] = s[i + start];
	res[i] = '\0';
	return (res);
}
