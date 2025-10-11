/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:08:53 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/11 10:43:41 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"

int	check_arg(int argc, char **argv, t_stack *stackA, t_stack *stackB)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
		{
			write(2, "Error\n", 6);
			deallocate(stackA);
			deallocate(stackB);
			exit (2);
		}
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			write(2, "Error\n", 6);
			deallocate(stackA);
			deallocate(stackB);
			exit (2);
		}
		i++;
	}
	return (1);
}

void	check_dup(t_stack *stackA, t_stack *stackB)
{
	t_node	*curr;
	t_node	*cmp;

	if (!stackA || !stackA->head)
		exit (2);
	curr = stackA->head;
	while (1)
	{
		cmp = curr->next;
		while (cmp != stackA->head)
		{
			if (curr->x == cmp->x)
			{
				write(2, "Error\n", 6);
				deallocate(stackA);
				deallocate(stackB);
				exit (2);
			}
			cmp = cmp->next;
		}
		if (curr == stackA->head)
			break ;
		curr = curr->next;
	}
}

void	deallocate(t_stack *stack)
{
	t_node	*curr;
	t_node	*temp;

	if (stack == NULL || stack->head == NULL)
		return ;
	stack->head->prev->next = NULL;
	curr = stack->head;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	stack->head = NULL;
	stack->tail = NULL;
}

int	is_sorted(t_stack *stackA, t_stack *stackB)
{
	t_node	*curr;

	if (!stackA || !stackA->head)
		exit(2);
	curr = stackA->head;
	while (curr->next != stackA->head)
	{
		if (curr->x > curr->next->x)
		{
			return (0);
		}
		curr = curr->next;
	}
	deallocate(stackA);
	deallocate(stackB);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_b.head = NULL;
	stack_b.tail = NULL;
	check_arg(argc, argv, &stack_a, &stack_b);
	if (argc <= 2)
	{
		deallocate(&stack_a);
		deallocate(&stack_b);
		exit (2);
	}
	get_num(argc, argv, &stack_a, &stack_b);
	check_dup(&stack_a, &stack_b);
	is_sorted(&stack_a, &stack_b);
	sort_num(argc, &stack_a, &stack_b);
	deallocate(&stack_a);
	deallocate(&stack_b);
	return (0);
}
