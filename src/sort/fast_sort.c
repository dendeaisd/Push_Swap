/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:48:15 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 11:26:04 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	divide_reduction(t_data *data, t_part *max)
{
	t_stack	*a;

	a = &data->a;
	if (max->location != top_a)
		return ;
	if (max->size == 3)
	{
		if (is_consecutive(rank_of(a, 1), rank_of(a, 2), rank_of(a, 3), \
		rank_of(a, 4)) && a_part_sort(data, 4))
		{
			sort_three(data, max);
			return ;
		}
	}
	else if (max->size > 1 && rank_of(a, 1) == rank_of(a, 3) - 1 \
			&& a_part_sort(data, 3))
	{
		op_sa(data);
		max->size--;
	}
	if (a_part_sort(data, 1))
		max->size--;
}

bool	a_part_sort(t_data *data, int src)
{
	int	curr_index;
	int	expected_rank;

	curr_index = get_start_index(&data->a, src);
	expected_rank = 1;
	while (curr_index != data->a.bottom)
	{
		if (data->a.stack[curr_index] != expected_rank)
			return (false);
		++expected_rank;
		curr_index = next_index(&data->a, curr_index);
	}
	return (true);
}

int	get_start_index(t_stack *a, int src)
{
	int	index;

	index = a->top;
	while (src > 1)
	{
		index = next_index(a, index);
		--src;
	}
	return (index);
}

bool	is_consecutive(int a, int b, int c, int d)
{
	sort_three_ints(&a, &b, &c);
	return ((d - c == 1) && (c - b == 1) && (b - a == 1));
}

void	sort_three_ints(int *a, int *b, int *c)
{
	if (*a > *b)
		swap_ints(a, b);
	if (*a > *c)
		swap_ints(a, c);
	if (*b > *c)
		swap_ints(b, c);
}
