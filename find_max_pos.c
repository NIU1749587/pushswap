/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfuster <gfuster@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:11:37 by gfuster           #+#    #+#             */
/*   Updated: 2025/09/28 10:10:01 by gfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
