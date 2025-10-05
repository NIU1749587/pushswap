/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:39:55 by aiguerre          #+#    #+#             */
/*   Updated: 2025/09/28 11:40:01 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	atof_aux(const char *str)
{
	float	result;
	float	decimal;
	float	divisor;

	result = 0.0;
	decimal = 0.0;
	divisor = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			decimal += (*str - '0') / divisor;
			divisor *= 10.0;
			str++;
		}
	}
	return (result + decimal);
}

float	ft_atof(const char *str)
{
	float	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = atof_aux(str);
	return (sign * result);
}
