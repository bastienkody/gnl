/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:12:03 by bguillau          #+#    #+#             */
/*   Updated: 2022/12/01 18:46:59 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// Exec sans argument : lit 1 ligne de get_next_line.c
// Lire plusieurs lignes --> donner nb lignes en argv[1]
// Lire dans un ficher --> argv[1] = nb lignes, argv[2] = path_file


int	main(int argc, char **argv)
{
	int		line_to_read;
	int		fd;
	char	*file_path;
	char	*line;

	line_to_read = 1;
	file_path = "get_next_line.c";
	if (argc >= 2)
		line_to_read = atoi(argv[1]);
	if (argc == 3)
		file_path = argv[2];
	else
		(void) argv;
	fd = open(file_path, O_RDONLY);
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
