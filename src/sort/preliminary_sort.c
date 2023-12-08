/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 04:09:06 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 09:39:34 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	preliminary_sort(t_data *data, t_part *to_sort)
{
	while (to_sort->location != top_a && to_sort->size)
	{
		if (rank_of(&data->a, 1) == segment_rank(data, to_sort, 1) + 1)
			sort_one(data, to_sort);
		else if (rank_of(&data->a, 1) == segment_rank(data, to_sort, 2) + 1
			&& to_sort->size > 1)
			cases(data, to_sort);
		else
			break ;
	}
}

void	cases(t_data *data, t_part *to_sort)
{
	if (to_sort->location == top_b)
		process_top_b(data, to_sort);
	else if (to_sort->location == bottom_a)
		process_bottom_a(data, to_sort);
	else if (to_sort->location == bottom_b)
		process_bottom_b(data, to_sort);
	to_sort->size--;
}

void	process_top_b(t_data *data, t_part *to_sort)
{
	swap_and_push(data, 'b');
	if (rank_of(&data->b, 1) == rank_of(&data->a, 1) - 1)
	{
		op_pa(data);
		to_sort->size--;
	}
}

void	process_bottom_a(t_data *data, t_part *to_sort)
{
	double_rrotate(data, 'a');
	op_sa(data);
	if (rank_of(&data->a, 1) == rank_of(&data->a, 2) - 1)
		to_sort->size--;
	else
		op_ra(data);
}

void	process_bottom_b(t_data *data, t_part *to_sort)
{
	double_rrotate(data, 'b');
	op_pa(data);
	if (rank_of(&data->b, 1) == rank_of(&data->a, 1) - 1)
	{
		op_pa(data);
		to_sort->size--;
	}
	else
		op_rb(data);
}
