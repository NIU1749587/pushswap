/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:23:03 by aiguerre          #+#    #+#             */
/*   Updated: 2025/08/18 20:23:08 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	char	*duplicate;
	size_t	i;

	i = 0;
	duplicate = (char *)malloc(ft_strlen(s) + 1);
	if (duplicate == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int character)
{
	char	*temp;

	temp = (char *)str;
	while (*temp && *temp != character)
		temp++;
	if (*temp == character)
		return (temp);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*allocated;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	allocated = malloc(total_size);
	if (!allocated)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		allocated[i] = '\0';
		i++;
	}
	return (allocated);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
