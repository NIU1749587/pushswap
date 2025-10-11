/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiguerre <aiguerre@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:11:34 by aiguerre          #+#    #+#             */
/*   Updated: 2025/10/11 11:11:47 by aiguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_node
{
	int				x;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

// BRING TO TOP
void			bring_max_to_top(t_stack *stackB);
void			bring_second_max_to_top(t_stack *stackB);
int				bring_max_to_top_cost(t_stack *stackB);
int				bring_second_max_to_top_cost(t_stack *stackB);

// CALCULATE MEDIAN
int				get_median(t_stack *stack);
int				stack_to_array(t_stack *stack, int **arr);
void			bubblesort(int arr[], int n);
int				count_lowers(t_stack *stack, int pivot);
int				calculate_median_lowers(t_stack *stack, int pivot);

// FIND MIN & MAX
int				find_max_pos(t_stack *stack);
int				find_second_max_pos(t_stack *stack);
void			min_to_top(t_stack *stack);
int				find_min_pos(t_stack *stack);

// MAIN
int				check_arg(int argc, char **argv,
					t_stack *stackA, t_stack *stackB);
void			check_dup(t_stack *stackA, t_stack *stackB);
void			deallocate(t_stack *stack);
int				is_sorted(t_stack *stackA, t_stack *stackB);
int				main(int argc, char **argv);

// PARSE NUM
void			get_num(int argc, char **argv,
					t_stack *stackA, t_stack *stackB);
void			add_bottom(t_stack *stackA, t_stack *stackB, int value);

// PUSH
void			pa(t_stack *stackA, t_stack *stackB);
void			pb(t_stack *stackA, t_stack *stackB);

// REVROTATE
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stackA, t_stack *stackB);

// ROTATE
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stackA, t_stack *stackB);

// SORT
void			sort_three(t_stack *stack);
void			sort_five(t_stack *stackA, t_stack *stackB);
void			sort_num(int argc, t_stack *stackA, t_stack *stackB);
void			move_lowers_to_b(t_stack *stackA, t_stack *stackB);
void			bring_to_top(t_stack *stackA, t_stack *stackB);

// SWAP
int				stack_length(t_stack *stack);
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stackA, t_stack *stackB);
