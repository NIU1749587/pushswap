/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:16:55 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/05 15:16:58 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_length(t_stack *stack)
{
	t_node	*curr;
	int		count;

	if (stack == NULL || stack->head == NULL)
		return (0);
	count = 1;
	curr = stack->head->next;
	while (curr != stack->head)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}

void	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack->head == NULL || stack->head->next == stack->head)
		return ;
	if (stack->head->next == stack->tail && stack_length(stack) == 2)
	{
		stack->head = stack->tail;
		stack->tail = stack->tail->next;
		write(1, "sa\n", 3);
		return ;
	}
	first = stack->head;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->prev = last;
	last->next = second;
	second->next = first;
	first->prev = second;
	stack->head = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack->head == NULL || stack->head->next == stack->head)
		return ;
	if (stack->head->next == stack->tail && stack_length(stack) == 2)
	{
		stack->head = stack->tail;
		stack->tail = stack->tail->next;
		write(1, "sb\n", 3);
		return ;
	}
	first = stack->head;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->prev = last;
	last->next = second;
	second->next = first;
	first->prev = second;
	stack->head = second;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	sa(stackA);
	sb(stackB);
	write(1, "ss\n", 3);
}
