/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:49:47 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 17:46:18 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	rotate(t_stack *stack)
{
	int	new_top;

	new_top = next_index(stack, stack->top);
	if (!stack || !(stack->stack))
		return ;
	if (is_full(stack))
		stack->bottom = stack->top;
	else
	{
		stack->bottom = next_index(stack, stack->bottom);
		stack->stack[stack->bottom] = stack->stack[stack->top];
		stack->stack[stack->top] = 0;
	}
	stack->top = new_top;
}

void	op_ra(t_data *data)
{
	rotate(&data->a);
	save_op(data, ra);
}

void	op_rb(t_data *data)
{
	rotate(&data->b);
	save_op(data, rb);
}

void	op_rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	save_op(data, rr);
}

void	rotate_stack(t_data *data, t_location stack)
{
	if (stack == top_a || stack == bottom_a)
		op_ra(data);
	else if (stack == top_b || stack == bottom_b)
		op_rb(data);
}
