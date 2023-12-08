/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:47:10 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/01 06:21:45 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	divide(t_data *data, t_part *slice, t_split_dest *dest)
{
	int	pivot_1;
	int	pivot_2;
	int	max_value;
	int	next_value;

	init_size(&dest->min, &dest->mid, &dest->max);
	set_split_loc(slice->location, &dest->min, &dest->mid, &dest->max);
	triple_part_pivot(slice->location, slice->size, &pivot_1, &pivot_2);
	max_value = segment_max_rank(data, slice);
	while (slice->size--)
	{
		next_value = segment_rank(data, slice, 1);
		if (next_value > max_value - pivot_2)
		{
			dest->max.size += move(data, \
					slice->location, dest->max.location);
			divide_reduction(data, &dest->max);
			if (a_part_sort(data, 1) && slice->size)
				preliminary_sort(data, slice);
		}
		else if (next_value > max_value - pivot_1)
			dest->mid.size += move(data, slice->location, dest->mid.location);
		else
			dest->min.size += move(data, slice->location, dest->min.location);
	}
}

void	init_size(t_part *min, t_part *mid, t_part *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	set_split_loc(t_location location, t_part *min, \
		t_part *mid, t_part *max)
{
	if (location == top_a)
	{
		min->location = bottom_b;
		mid->location = top_b;
		max->location = bottom_a;
	}
	else if (location == bottom_a)
	{
		min->location = bottom_b;
		mid->location = top_b;
		max->location = top_a;
	}
	else if (location == top_b)
	{
		min->location = bottom_b;
		mid->location = bottom_a;
		max->location = top_a;
	}
	else if (location == bottom_b)
	{
		min->location = top_b;
		mid->location = bottom_a;
		max->location = top_a;
	}
}

void	triple_part_pivot(t_location loc, int crt_size, \
		int *pivot_1, int *pivot_2)
{
	*pivot_2 = crt_size / 3;
	if (loc == top_a || loc == bottom_a)
		*pivot_1 = 2 * crt_size / 3;
	if (loc == top_b || loc == bottom_b)
		*pivot_1 = crt_size / 2;
	if ((loc == top_a || loc == bottom_a) && crt_size < 16)
		*pivot_1 = crt_size;
	if (loc == bottom_b && crt_size < 10)
		*pivot_2 = crt_size / 2;
}
