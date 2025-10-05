/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:17:07 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/05 15:17:14 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_node	*extract_top(t_stack *stack)
{
	t_node	*top;

	top = stack->head;
	if (stack->head == stack->tail)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = top->next;
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
	}
	return (top);
}

static void	insert_top(t_stack *stack, t_node *node)
{
	if (!stack->head)
	{
		node->next = node;
		node->prev = node;
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		node->prev = stack->tail;
		stack->head->prev = node;
		stack->tail->next = node;
		stack->head = node;
	}
}

void	pb(t_stack *stackA, t_stack *stackB)
{
	t_node	*top;

	if (!stackA->head)
		return ;
	top = extract_top(stackA);
	insert_top(stackB, top);
	write(1, "pb\n", 3);
}

void	pa(t_stack *stackA, t_stack *stackB)
{
	t_node	*top;

	if (!stackB->head)
		return ;
	top = extract_top(stackB);
	insert_top(stackA, top);
	write(1, "pa\n", 3);
}
