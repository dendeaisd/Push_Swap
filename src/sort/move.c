/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:47:41 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/01 08:45:30 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	move(t_data *data, t_location from, t_location dest)
{
	if (from == top_a)
		move_top_a(data, dest);
	else if (from == top_b)
		move_top_b(data, dest);
	else if (from == bottom_a)
		move_bottom_a(data, dest);
	else if (from == bottom_b)
		move_bottom_b(data, dest);
	return (1);
}

void	move_top_a(t_data *data, t_location dest)
{
	if (dest == top_b)
		op_pb(data);
	else if (dest == bottom_a)
		op_ra(data);
	else if (dest == bottom_b)
	{
		op_pb(data);
		op_rb(data);
	}
}

void	move_top_b(t_data *data, t_location dest)
{
	if (dest == top_a)
		op_pa(data);
	else if (dest == bottom_b)
		op_rb(data);
	else if (dest == bottom_a)
	{
		op_pa(data);
		op_ra(data);
	}
}

void	move_bottom_a(t_data *data, t_location dest)
{
	if (dest == top_a)
		op_rra(data);
	else if (dest == top_b)
	{
		op_rra(data);
		op_pb(data);
	}
	else if (dest == bottom_b)
	{
		op_rra(data);
		op_pb(data);
		op_rb(data);
	}
}

void	move_bottom_b(t_data *data, t_location dest)
{
	if (dest == top_b)
		op_rrb(data);
	else if (dest == top_a)
	{
		op_rrb(data);
		op_pa(data);
	}
	else if (dest == bottom_a)
	{
		op_rrb(data);
		op_pa(data);
		op_ra(data);
	}
}
