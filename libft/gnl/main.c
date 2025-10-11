/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:48:18 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/11 10:48:25 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_number;

	if (argc != 2)
	{
		printf("Uso: %s <archivo>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	line_number = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("Línea %d: %s", line_number++, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
