/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:15:57 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/05 15:16:12 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rra(t_stack *stack)
{
	if (!stack || !stack->head || stack->head->next == stack->head)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	if (!stack || !stack->head || stack->head->next == stack->head)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stackA, t_stack *stackB)
{
	rra(stackA);
	rrb(stackB);
	write(1, "rrr\n", 4);
}
