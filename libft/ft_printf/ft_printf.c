/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:27:22 by aiguerre          #+#    #+#             */
/*   Updated: 2025/07/29 10:27:24 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_character(va_list args, const char character)
{
	int	len;

	len = 0;
	if (character == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (character == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (character == 'p')
	{
		len += ft_print_pointer(va_arg(args, unsigned long));
	}
	else if (character == 'd' || character == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (character == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (character == 'x' || character == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), character);
	else if (character == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_character(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
