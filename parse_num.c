/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:39:12 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/11 11:39:17 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	get_numbers(int argc, char **argv, t_stack *stackA, t_stack *stackB)
{
	int		i;

	i = 1;
	if (argc > 2)
	{
		while (argv[i])
		{
			add_bottom(stackA, stackB, ft_atoi(argv[i]));
			i++;
		}
	}
}

static void	init_stack(t_stack *stack, t_node *new_node)
{
	new_node->prev = new_node;
	new_node->next = new_node;
	stack->head = new_node;
	stack->tail = new_node;
}

static void	append_node(t_stack *stack, t_node *new_node)
{
	new_node->prev = stack->tail;
	new_node->next = stack->head;
	stack->tail->next = new_node;
	stack->head->prev = new_node;
	stack->tail = new_node;
}

void	add_bottom(t_stack *stackA, t_stack *stackB, int value)
{
	t_node	*new_node;

	(void)stackB;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		deallocate(stackA);
		deallocate(stackB);
		exit(2);
	}
	new_node->x = value;
	if (stackA->head == NULL)
		init_stack(stackA, new_node);
	else
		append_node(stackA, new_node);
}
