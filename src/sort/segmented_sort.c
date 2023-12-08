/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 04:10:01 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 10:14:31 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	segmented_sort(t_data *data)
{
	t_part	all_parts;

	all_parts.location = top_a;
	all_parts.size = data->a.size;
	recursive_segmented_sort(data, &all_parts);
}

void	recursive_segmented_sort(t_data *data, t_part *to_sort)
{
	t_split_dest	dest;

	if (to_sort->location == bottom_b
		&& current_size(&data->b) == to_sort->size)
		to_sort->location = top_b;
	else if (to_sort->location == bottom_a
		&& current_size(&data->a) == to_sort->size)
		to_sort->location = top_a;
	preliminary_sort(data, to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			sort_three(data, to_sort);
		else if (to_sort->size == 2)
			sort_two(data, to_sort);
		else if (to_sort->size == 1)
			sort_one(data, to_sort);
		return ;
	}
	divide(data, to_sort, &dest);
	recursive_segmented_sort(data, &dest.max);
	recursive_segmented_sort(data, &dest.mid);
	recursive_segmented_sort(data, &dest.min);
}

void	sort_two(t_data *data, t_part *to_sort)
{
	if (to_sort->location == bottom_a || to_sort->location == bottom_b
		|| to_sort->location == top_b)
	{
		move(data, to_sort->location, top_a);
		move(data, to_sort->location, top_a);
	}
	if (rank_of(&data->a, 1) > rank_of(&data->a, 2))
		op_sa(data);
	to_sort->size -= 2;
}

void	sort_one(t_data *data, t_part *to_sort)
{
	if (to_sort->location == bottom_a || to_sort->location == bottom_b
		|| to_sort->location == top_b)
		move(data, to_sort->location, top_a);
	to_sort->size -= 1;
}
