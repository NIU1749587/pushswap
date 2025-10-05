/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfuster <gfuster@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:29:25 by gfuster           #+#    #+#             */
/*   Updated: 2025/09/27 15:30:19 by gfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	bring_max_to_top(t_stack *stackB)
{
	int	max_pos;
	int	size;
	int	moves_up;
	int	moves_down;

	if (stackB == NULL || stackB->head == NULL)
		return ;
	max_pos = find_max_pos(stackB);
	size = stack_length(stackB);
	moves_up = max_pos;
	moves_down = size - max_pos;
	if (moves_up <= moves_down)
	{
		while (max_pos-- > 0)
			rb(stackB);
	}
	else
	{
		while (moves_down-- > 0)
			rrb(stackB);
	}
}

void	bring_second_max_to_top(t_stack *stackB)
{
	int	second_pos;
	int	size;
	int	moves_up_second;
	int	moves_down_second;

	if (stackB == NULL || stackB->head == NULL)
		return ;
	second_pos = find_second_max_pos(stackB);
	size = stack_length(stackB);
	moves_up_second = second_pos;
	moves_down_second = size - second_pos;
	if (moves_up_second <= moves_down_second)
	{
		while (second_pos-- > 0)
			rb(stackB);
	}
	else
	{
		while (moves_down_second-- > 0)
			rrb(stackB);
	}
}

int	bring_max_to_top_cost(t_stack *stackB)
{
	int	max_pos;
	int	size;
	int	moves_up;
	int	moves_down;

	if (stackB == NULL || stackB->head == NULL)
		return (-1);
	max_pos = find_max_pos(stackB);
	size = stack_length(stackB);
	moves_up = max_pos;
	moves_down = size - max_pos;
	if (moves_up <= moves_down)
	{
		return (moves_up);
	}
	else
	{
		return (moves_down);
	}
}

int	bring_second_max_to_top_cost(t_stack *stackB)
{
	int	second_pos;
	int	size;
	int	moves_up;
	int	moves_down;

	if (stackB == NULL || stackB->head == NULL)
		return (-1);
	second_pos = find_second_max_pos(stackB);
	size = stack_length(stackB);
	moves_up = second_pos;
	moves_down = size - second_pos;
	if (moves_up <= moves_down)
	{
		return (moves_up);
	}
	else
	{
		return (moves_down);
	}
}
