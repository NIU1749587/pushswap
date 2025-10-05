/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:43:53 by aiguerre          #+#    #+#             */
/*   Updated: 2025/07/29 10:44:24 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	aux(unsigned long ptr)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789abcdef";
	if (ptr >= 16)
		len += aux(ptr / 16);
	len += ft_putchar(hex[ptr % 16]);
	return (len);
}

int	ft_print_pointer(unsigned long ptr)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789abcdef";
	if (!ptr)
		return (write(1, "(nil)", 5));
	len += ft_putstr("0x");
	if (ptr >= 16)
		len += aux(ptr / 16);
	len += ft_putchar(hex[ptr % 16]);
	return (len);
}
