/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:51:29 by aiguerre          #+#    #+#             */
/*   Updated: 2025/05/10 18:51:34 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_plus_s2;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	s1_plus_s2 = malloc((len + 1) * sizeof(char));
	if (!s1_plus_s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s1_plus_s2[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s1_plus_s2[i++] = s2[j++];
	s1_plus_s2[i] = '\0';
	return (s1_plus_s2);
}
