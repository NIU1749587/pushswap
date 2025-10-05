/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfuster <gfuster@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:24:49 by gfuster           #+#    #+#             */
/*   Updated: 2025/09/27 15:31:18 by gfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
