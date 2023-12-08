/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:48:28 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 09:44:12 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_data *data, t_part *to_sort)
{
	t_stack	*stack;
	int		max;

	stack = stack_loc(data, to_sort->location);
	max = segment_max_rank(data, to_sort);
	if (to_sort->location == top_a)
		three_top_a(data, to_sort, stack, max);
	else if (to_sort->location == bottom_a)
		three_bottom_a(data, to_sort, stack, max);
	else if (to_sort->location == top_b)
		three_top_b(data, to_sort, stack, max);
	else if (to_sort->location == bottom_b)
		three_bottom_b(data, to_sort, stack, max);
}

void	three_top_a(t_data *data, t_part *to_sort, \
		t_stack *stack, int max)
{
	if (stack->stack[stack->top] == max)
	{
		op_sa(data);
		op_ra(data);
		op_sa(data);
		op_rra(data);
	}
	else if (stack->stack[next_index(stack, stack->top)] == max)
	{
		op_ra(data);
		op_sa(data);
		op_rra(data);
	}
	to_sort->location = top_a;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	three_top_b(t_data *data, t_part *to_sort, \
		t_stack *stack, int max)
{
	op_pa(data);
	if (stack->stack[stack->top] == max)
	{
		op_pa(data);
		op_sa(data);
	}
	else if (stack->stack[next_index(stack, stack->top)] == max)
	{
		op_sb(data);
		op_pa(data);
		op_sa(data);
	}
	else
		op_pa(data);
	op_pa(data);
	to_sort->location = top_a;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	three_bottom_a(t_data *data, t_part *to_sort, \
		t_stack *stack, int max)
{
	op_rra(data);
	op_rra(data);
	if (stack->stack[stack->top] == max)
	{
		op_sa(data);
		op_rra(data);
	}
	else if (stack->stack[next_index(stack, stack->top)] == max)
		op_rra(data);
	else
	{
		op_pb(data);
		op_rra(data);
		op_sa(data);
		op_pa(data);
	}
	to_sort->location = top_a;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	three_bottom_b(t_data *data, t_part *to_sort, \
		t_stack *stack, int max)
{
	op_rrb(data);
	op_rrb(data);
	if (stack->stack[stack->top] == max)
	{
		op_pa(data);
		op_rrb(data);
	}
	else if (stack->stack[next_index(stack, stack->top)] == max)
	{
		op_sb(data);
		op_pa(data);
		op_rrb(data);
	}
	else
	{
		op_rrb(data);
		op_pa(data);
	}
	to_sort->location = top_b;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}
