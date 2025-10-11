/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_and_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:40:15 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/11 10:40:18 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	update_max_and_second(t_stack *stack, int *max,
		int *second, int *pos_second)
{
	t_node	*curr;
	int		i;
	int		pos_max;

	curr = stack->head->next;
	i = 1;
	pos_max = 0;
	while (curr != stack->head)
	{
		if (curr->x > *max)
		{
			*second = *max;
			*pos_second = pos_max;
			*max = curr->x;
			pos_max = i;
		}
		else if (curr->x > *second && curr->x < *max)
		{
			*second = curr->x;
			*pos_second = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos_max);
}

int	find_max_pos(t_stack *stack)
{
	t_node	*curr;
	int		max;
	int		pos;
	int		i;

	if (stack == NULL || stack->head == NULL)
		return (-1);
	curr = stack->head->next;
	max = stack->head->x;
	pos = 0;
	i = 0;
	while (curr != stack->head)
	{
		i++;
		if (curr->x > max)
		{
			max = curr->x;
			pos = i;
		}
		curr = curr->next;
	}
	return (pos);
}

int	find_second_max_pos(t_stack *stack)
{
	int	max;
	int	second;
	int	pos_max;
	int	pos_second;

	if (stack == NULL || stack->head == NULL)
		return (-1);
	max = stack->head->x;
	second = INT_MIN;
	pos_second = -1;
	pos_max = update_max_and_second(stack, &max, &second, &pos_second);
	if (pos_second == -1)
		pos_second = pos_max;
	return (pos_second);
}

void	min_to_top(t_stack *stack)
{
	int		pos;
	int		len;
	t_node	*curr;

	pos = find_min_pos(stack);
	len = 1;
	curr = stack->head->next;
	while (curr != stack->head)
	{
		len++;
		curr = curr->next;
	}
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = len - pos;
		while (pos-- > 0)
			rra(stack);
	}
}

int	find_min_pos(t_stack *stack)
{
	t_node	*curr;
	int		min;
	int		pos;
	int		i;

	if (stack == NULL || stack->head == NULL)
		return (-1);
	curr = stack->head->next;
	min = stack->head->x;
	pos = 0;
	i = 0;
	while (curr != stack->head)
	{
		i++;
		if (curr->x < min)
		{
			min = curr->x;
			pos = i;
		}
		curr = curr->next;
	}
	return (pos);
}
