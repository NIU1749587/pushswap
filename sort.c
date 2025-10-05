/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfuster <gfuster@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:36:48 by gfuster           #+#    #+#             */
/*   Updated: 2025/09/27 15:39:43 by gfuster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_numbers(int argc, t_stack *stackA, t_stack *stackB)
{
	if (!stackA || !stackA->head)
		exit(2);
	if (argc == 4)
		sort_three(stackA);
	else if (argc == 6 || argc == 5)
		sort_five(stackA, stackB);
	else if (argc == 2 || argc > 6)
	{
		while (stack_length(stackA) > 2)
		{
			move_lowers_to_b(stackA, stackB);
		}
		if (stackA->head->x > stackA->head->next->x)
			sa(stackA);
	}
	while (stackB->head != NULL)
	{
		bring_to_top(stackA, stackB);
	}
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->x;
	b = stack->head->next->x;
	c = stack->head->next->next->x;
	if (a > b && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > c && b < c)
		ra(stack);
	else if (a < b && a > c)
		rra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_five(t_stack *stackA, t_stack *stackB)
{
	min_to_top(stackA);
	pb(stackA, stackB);
	min_to_top(stackA);
	pb(stackA, stackB);
	sort_three(stackA);
	pa(stackA, stackB);
	pa(stackA, stackB);
}

void	move_lowers_to_b(t_stack *stackA, t_stack *stackB)
{
	int	pivot;
	int	items_to_move;
	int	items_moved;
	int	median_b;

	if (stack_length(stackA) <= 2)
		return ;
	pivot = get_median(stackA);
	items_to_move = count_lowers(stackA, pivot);
	median_b = calculate_median_lowers(stackA, pivot);
	items_moved = 0;
	while (items_moved < items_to_move)
	{
		if (stackA->head->x <= pivot)
		{
			pb(stackA, stackB);
			items_moved++;
			if (stackB->head->x < median_b)
				rb(stackB);
		}
		else
		{
			ra(stackA);
		}
	}
}

void	bring_to_top(t_stack *stackA, t_stack *stackB)
{
	int	cost_max;
	int	cost_second;

	if (stackB == NULL || stackB->head == NULL)
		return ;
	cost_max = bring_max_to_top_cost (stackB);
	cost_second = bring_second_max_to_top_cost(stackB);
	if (cost_max <= cost_second)
	{
		bring_max_to_top(stackB);
		pa(stackA, stackB);
	}
	else
	{
		bring_second_max_to_top(stackB);
		pa(stackA, stackB);
		bring_max_to_top(stackB);
		pa(stackA, stackB);
		sa(stackA);
	}
}
