/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:48:59 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 09:05:25 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort(t_data *data)
{
	if (data->a.size <= 1 || is_sorted(data))
		return ;
	else if (data->a.size == 3)
		sort_three_a(data);
	else if (data->a.size == 5)
		sort_five_a(data);
	else
		segmented_sort(data);
}

void	sort_three_a(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = rank_of(&data->a, 1);
	second = rank_of(&data->a, 2);
	third = rank_of(&data->a, 3);
	if (first < second && second < third)
		return ;
	else if (first > second && second < third && first < third)
		op_sa(data);
	else if (first > second && second > third)
	{
		op_sa(data);
		op_rra(data);
	}
	else if (first > second && second < third && first > third)
		op_ra(data);
	else if (first < second && second > third && first < third)
	{
		op_sa(data);
		op_ra(data);
	}
	else if (first < second && second > third && first > third)
		op_rra(data);
}

void	sort_five_a(t_data *data)
{
	while (current_size(&data->a) > 3)
	{
		if (rank_of(&data->a, 1) == 1 || rank_of(&data->a, 1) == 2)
			op_pb(data);
		else
			op_ra(data);
	}
	if (rank_of(&data->b, 1) < rank_of(&data->b, 2))
		op_sb(data);
	sort_three_a(data);
	op_pa(data);
	op_pa(data);
}
