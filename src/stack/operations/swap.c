/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:49:59 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 09:06:02 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	swap(t_stack *stack)
{
	int	next_top_idx;
	int	tmp;

	next_top_idx = next_index(stack, stack->top);
	tmp = stack->stack[next_top_idx];
	if (!stack || !(stack->stack))
		return ;
	if (stack->stack[next_top_idx] != 0)
	{
		stack->stack[next_top_idx] = stack->stack[stack->top];
		stack->stack[stack->top] = tmp;
	}
}

void	op_sa(t_data *data)
{
	swap(&data->a);
	save_op(data, sa);
}

void	op_sb(t_data *data)
{
	swap(&data->b);
	save_op(data, sb);
}

void	op_ss(t_data *data)
{
	swap(&data->a);
	swap(&data->b);
	save_op(data, ss);
}

void	swap_and_push(t_data *data, char stack)
{
	if (stack == 'a')
	{
		op_sa(data);
		op_pb(data);
	}
	else if (stack == 'b')
	{
		op_sb(data);
		op_pa(data);
	}
}
