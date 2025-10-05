/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:23:19 by aiguerre          #+#    #+#             */
/*   Updated: 2025/08/18 20:23:22 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_free(char *stored_data, char *new_data)
{
	char	*joined;

	joined = ft_strjoin(stored_data, new_data);
	free(stored_data);
	return (joined);
}

char	*get_remaining_after_line(char *buffer)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	remaining = ft_calloc(sizeof(char), ft_strlen(buffer) - i + 1);
	if (!remaining)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		remaining[j++] = buffer[i++];
	free(buffer);
	return (remaining);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *stored_data)
{
	int		bytes_read;
	char	*read_buffer;

	if (!stored_data)
		stored_data = ft_calloc(1, 1);
	if (!stored_data)
		return (NULL);
	read_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!read_buffer)
		return (free(stored_data), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stored_data, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			free(stored_data);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		stored_data = join_and_free(stored_data, read_buffer);
	}
	free(read_buffer);
	return (stored_data);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = get_remaining_after_line(buffer);
	return (line);
}
