/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfuster <gfuster@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:27:27 by gfuster           #+#    #+#             */
/*   Updated: 2025/09/27 15:28:38 by gfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
