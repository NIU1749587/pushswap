/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfuster <gfuster@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:40:40 by gfuster           #+#    #+#             */
/*   Updated: 2025/09/27 17:02:44 by gfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/libft.h"

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

void	add_bottom(t_stack *stackA, t_stack *stackB, int value)
{
	t_node	*new_node;

	(void)stackB;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_all(stackA, stackB);
		exit(2);
	}
	new_node->x = value;
	if (stackA->head == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		stackA->head = new_node;
		stackA->tail = new_node;
	}
	else
	{
		new_node->prev = stackA->tail;
		new_node->next = stackA->head;
		stackA->tail->next = new_node;
		stackA->head->prev = new_node;
		stackA->tail = new_node;
	}
}
