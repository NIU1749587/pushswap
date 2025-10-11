/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:48:36 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/11 10:48:38 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "ft_printf.h"

char	*get_next_line(int fd);

int	*open_files(int argc, char **argv)
{
	int	i;
	int	*fds;

	fds = malloc(sizeof(int) * (argc - 1));
	if (!fds)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		fds[i] = open(argv[i + 1], O_RDONLY);
		if (fds[i] < 0)
		{
			while (--i >= 0)
				if (fds[i] >= 0)
					close(fds[i]);
			free(fds);
			return (NULL);
		}
		i++;
	}
	return (fds);
}

int	*init_active(int argc)
{
	int	i;
	int	*active;

	active = malloc(sizeof(int) * (argc - 1));
	if (!active)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		active[i] = 1;
		i++;
	}
	return (active);
}

int	handle_line(int fd, int *active, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		active[i] = 0;
		return (1);
	}
	ft_printf("%s", line);
	free(line);
	return (0);
}

void	read_files(int argc, int *fds, int *active)
{
	int	i;
	int	files_left;

	files_left = argc - 1;
	while (files_left > 0)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (active[i] == 1)
				files_left -= handle_line(fds[i], active, i);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	*fds;
	int	*active;

	if (argc < 2)
	{
		write(2, "Uso: ./program archivo1 archivo2 ...\n", 38);
		return (1);
	}
	fds = open_files(argc, argv);
	if (!fds)
		return (1);
	active = init_active(argc);
	if (!active)
	{
		free(fds);
		return (1);
	}
	read_files(argc, fds, active);
	free(fds);
	free(active);
	return (0);
}
