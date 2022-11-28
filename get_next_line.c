/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:09:52 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/28 19:19:48 by bguillau         ###   ########.fr       */
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

int	idx_trig(char *buf)
{
	int	i;

	i = 0;
	if (*buf != -1)
		return (i);
	while (buf[i] == TRIG)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*cache;
	int				j;
	int				eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cache = "";
	buf[BUFFER_SIZE] = '\0';
	eof = 1;
	while (eof > 0)
	{
		j = idx_of(buf, '\n');
		if (j != -1)
		{
			cache = ft_strjoin(cache, ft_substr(buf, idx_trig(buf), j + 1 - idx_trig(buf))); // leaks
			while (j > -1)
				buf[j--] = TRIG;
			return (cache);
		}
		else
			cache = ft_strjoin(cache, ft_substr(buf, idx_trig(buf), ft_strlen(buf) - idx_trig(buf))); // leaks
		eof = read(fd, buf, BUFFER_SIZE);
	}
// si on eneleve la condition ci dessous on perd la derniere ligne si pas de \n en derniere ligne
// si on la laisse on continue a iterer sur les derniers char de buf (entre les trig et la fin de fichier sans \n)
// on pourrait laisser eof en static mais pas sur que ca aide en plus une seule var static
// il faudrait operer qch de special pour le clear du buf lorsque eof = 0
// il va falloir decouper en fonctionnalites anyway : 
//  - le clear du buffer (peut on se passer de j? ce serait cool... je pense que oui)
//  - l'assignation a cache egalement? 
//  - renommer cache en ligne aussi 
	if (!eof)
		return (cache);
	else // eof < 0
		return (NULL); // free_all needed?
}
