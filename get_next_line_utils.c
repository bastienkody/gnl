/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:53 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/25 12:48:59 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	slen;
	char	*s_tmp;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	s_tmp = (char *) s;
	c = (char) c;
	while (slen--)
	{
		if (*s_tmp == c)
			return (s_tmp);
		s_tmp++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;
	int		new_len;

	if (!s)
		return (NULL);
	if (!len || !ft_strlen(s) || start > ft_strlen(s) - 1)
	{
		res = malloc(1 * sizeof(char));
		*res = '\0';
		return (res);
	}
	if (len > ft_strlen(s) - start)
		new_len = ft_strlen(s) - start;
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
