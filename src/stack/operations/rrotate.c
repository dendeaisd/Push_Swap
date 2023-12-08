/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:49:38 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/03 13:54:04 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	rrotate(t_stack *stack)
{
	bool	is_full;
	int		new_bottom;

	is_full = (stack->size == current_size(stack));
	new_bottom = prev_index(stack, stack->bottom);
	if (!stack || !(stack->stack))
		return ;
	if (is_full)
		stack->top = stack->bottom;
	else
	{
		stack->top = prev_index(stack, stack->top);
		stack->stack[stack->top] = stack->stack[stack->bottom];
		stack->stack[stack->bottom] = 0;
	}
	stack->bottom = new_bottom;
}

void	op_rra(t_data *data)
{
	rrotate(&data->a);
	save_op(data, rra);
}

void	op_rrb(t_data *data)
{
	rrotate(&data->b);
	save_op(data, rrb);
}

void	op_rrr(t_data *data)
{
	rrotate(&data->a);
	rrotate(&data->b);
	save_op(data, rrr);
}

void	double_rrotate(t_data *data, char stack)
{
	if (stack == 'a')
	{
		op_rra(data);
		op_rra(data);
	}
	else if (stack == 'b')
	{
		op_rrb(data);
		op_rrb(data);
	}
}
