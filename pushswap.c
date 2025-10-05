/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:08:53 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/05 15:09:07 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free_all(stackA, stackB);
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
		free_all(&stack_a, &stack_b);
		exit (2);
	}
	get_numbers(argc, argv, &stack_a, &stack_b);
	check_duplicates(&stack_a, &stack_b);
	is_sorted(&stack_a, &stack_b);
	sort_numbers(argc, &stack_a, &stack_b);
	deallocate(&stack_a);
	deallocate(&stack_b);
	return (0);
}
