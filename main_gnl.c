/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:12:03 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/29 19:57:35 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// Pour lire plusieurs lignes merci de specifier ce nombre en unique argument de l'executable

in	main(int argc, char **argv)
{
	int		line_to_read;
	int		fd;
	char	*line;

	line_to_read = 1;
	if (argc == 2)
		line_to_read = atoi(argv[1]);
	else
		(void) argv;
	fd = open("test3.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("fd < 0\nExiting program ...");
		return (-1);
	}
	else
		printf("fd :%i\n", fd);
	while (line_to_read--)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}
