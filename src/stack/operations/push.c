/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:49:26 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/03 13:52:59 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	int	dest_prev_idx;
	int	src_top_val;

	dest_prev_idx = prev_index(dest, dest->top);
	src_top_val = src->stack[src->top];
	if (!src || !dest || is_full(dest))
		return ;
	dest->stack[dest_prev_idx] = src_top_val;
	dest->top = dest_prev_idx;
	src->stack[src->top] = 0;
	src->top = next_index(src, src->top);
}

void	op_pa(t_data *data)
{
	push(&data->b, &data->a);
	save_op(data, pa);
}

void	op_pb(t_data *data)
{
	push(&data->a, &data->b);
	save_op(data, pb);
}

void	push_to_stack(t_data *data, t_location src, t_location dest)
{
	if (src == top_a && dest == top_b)
		op_pb(data);
	else if (src == top_b && dest == top_a)
		op_pa(data);
}

void	rrotate_and_push(t_data *data, t_location src, t_location dest)
{
	if (src == bottom_a)
		op_rra(data);
	else if (src == bottom_b)
		op_rrb(data);
	push_to_stack(data, src, dest);
}
