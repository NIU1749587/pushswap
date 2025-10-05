/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:33:14 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/05 14:33:17 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_arg(int argc, char **argv, t_stack *stackA, t_stack *stackB)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			write(2, "Error\n", 6);
			free_all(stackA, stackB);
			exit (2);
		}
		if (!valid_int(argv[i]))
		{
			write(2, "Error\n", 6);
			free_all(stackA, stackB);
			exit (2);
		}
		i++;
	}
	return (1);
}

void	check_duplicates(t_stack *stackA, t_stack *stackB)
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
				free_all(stackA, stackB);
				exit (2);
			}
			cmp = cmp->next;
		}
		if (curr == stackA->head)
			break ;
		curr = curr->next;
	}
}

int	valid_int(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}
