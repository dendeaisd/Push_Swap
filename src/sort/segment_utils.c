/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:47:25 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 09:44:12 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	segment_rank(t_data *data, t_part *part, int n)
{
	t_stack	*stack;
	int		index;

	stack = stack_loc(data, part->location);
	if (part->location == top_a || part->location == top_b)
		index = stack->top;
	else
		index = stack->bottom;
	while (--n > 0)
	{
		if (part->location == top_a || part->location == top_b)
			index = next_index(stack, index);
		else
			index = prev_index(stack, index);
	}
	return (stack->stack[index]);
}

int	segment_max_rank(t_data *data, t_part *part)
{
	t_stack	*stack;
	int		size;
	int		max_value;
	int		i;

	stack = stack_loc(data, part->location);
	size = part->size;
	if (part->location == top_a || part->location == top_b)
		i = stack->top;
	else
		i = stack->bottom;
	max_value = stack->stack[i];
	while (size--)
	{
		if (stack->stack[i] > max_value)
			max_value = stack->stack[i];
		i = update_index(stack, i, part->location);
	}
	return (max_value);
}

int	update_index(t_stack *stack, int index, t_location location)
{
	if (location == bottom_a || location == bottom_b)
		return (prev_index(stack, index));
	else
		return (next_index(stack, index));
}

t_stack	*stack_loc(t_data *data, t_location location)
{
	if (location == top_a || location == bottom_a)
		return (&data->a);
	return (&data->b);
}

void	swap_ints(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
