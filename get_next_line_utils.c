/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:53 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/21 12:58:36 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_cache
{
	char			*str;
	struct s_cache	next;
}	t_cache;

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

