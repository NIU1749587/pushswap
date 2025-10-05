/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:14:59 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/05 15:15:13 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(t_stack *stack)
{
	if (!stack || !stack->head || stack->head->next == stack->head)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	if (!stack || !stack->head || stack->head->next == stack->head)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stackA, t_stack *stackB)
{
	ra(stackA);
	rb(stackB);
	write(1, "rr\n", 3);
}
