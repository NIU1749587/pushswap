/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_median.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:41:59 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/11 10:42:06 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_median(t_stack *stack)
{
	int		*arr;
	int		n;
	double	median_value;

	arr = NULL;
	n = stack_to_array(stack, &arr);
	if (n == 0)
	{
		if (arr)
			free(arr);
		return (0);
	}
	bubblesort(arr, n);
	if (n % 2 == 0)
	{
		median_value = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
	}
	else
	{
		median_value = arr[n / 2];
	}
	free(arr);
	return (median_value);
}

int	stack_to_array(t_stack *stack, int **arr)
{
	int		n;
	int		i;
	t_node	*curr;

	if (!stack || !stack->head)
		return (0);
	n = stack_length(stack);
	*arr = malloc(n * sizeof(int));
	if (!*arr)
	{
		exit (1);
	}
	curr = stack->head;
	i = 0;
	while (i < n)
	{
		(*arr)[i] = curr->x;
		curr = curr->next;
		i++;
	}
	return (n);
}

void	bubblesort(int arr[], int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	count_lowers(t_stack *stack, int pivot)
{
	t_node	*curr;
	int		count;

	if (stack == NULL || stack->head == NULL)
		return (0);
	curr = stack->head;
	count = 0;
	while (1)
	{
		if (curr->x <= pivot)
			count++;
		curr = curr->next;
		if (curr == stack->head)
			break ;
	}
	return (count);
}

int	calculate_median_lowers(t_stack *stack, int pivot)
{
	t_node	*curr;
	int		sum;
	int		count;

	if (stack == NULL || stack->head == NULL)
		return (0);
	sum = 0;
	count = 0;
	curr = stack->head;
	while (1)
	{
		if (curr->x <= pivot)
		{
			sum = sum + curr->x;
			count++;
		}
		curr = curr->next;
		if (curr == stack->head)
			break ;
	}
	if (count == 0)
		return (0);
	return (sum / count);
}
