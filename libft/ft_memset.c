/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:00:10 by aiguerre          #+#    #+#             */
/*   Updated: 2025/05/07 14:00:22 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*s_new;

	s_new = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		s_new[i] = (unsigned char)c;
		i++;
	}
	return (s_new);
}
