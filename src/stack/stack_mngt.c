/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mngt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:49:15 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/08 03:04:02 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_data(t_data *data, int ac, char **av)
{
	init_stack(data, &data->a, ac);
	init_stack(data, &data->b, ac);
	fill_stack(data, &data->a, ac, av);
	data->op_list = NULL;
}

void	init_stack(t_data *data, t_stack *stack, int size)
{
	if (size < 0)
		error(data);
	stack->stack = ft_calloc(size + 1, sizeof(int));
	if (!stack->stack)
		error(data);
	stack->top = 0;
	stack->bottom = 0;
	stack->size = size;
}

bool	is_sorted(t_data *data)
{
	int	i;

	i = data->a.top;
	if (data->a.size == 0)
		return (true);
	if (data->a.size == 2)
	{
		if (data->a.stack[data->a.top] > data->a.stack[data->a.bottom])
			return (false);
		return (true);
	}
	while (i <= data->a.size - 2)
	{
		if (data->a.stack[i] > data->a.stack[i + 1])
			return (false);
		++i;
	}
	return (true);
}

void	error(t_data *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_data(t_data *data)
{
	free_stack(&data->a);
	free_stack(&data->b);
	if (data->op_list)
	{
		ft_lstclear(&data->op_list, NULL);
		data->op_list = NULL;
	}
}
