/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:50:15 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/08 02:35:33 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	fill_stack(t_data *data, t_stack *stack, int size, char **arg)
{
	int	*numbers;
	int	i;

	numbers = ft_calloc(size, sizeof(int));
	if (!numbers)
		error(data);
	i = 0;
	while (arg[i])
	{
		if (!valid_arg(arg[i]))
			error(data);
		numbers[i] = ft_atoi(arg[i]);
		++i;
	}
	check_duplication(data, numbers, size);
	calculate_rank(numbers, stack->stack, size);
	stack->bottom = size - 1;
	free(numbers);
}

bool	valid_arg(char *arg)
{
	long long	num;
	int			sign;

	sign = 1;
	if (*arg == '\0')
		return (false);
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
		if (*arg == '\0')
			return (false);
	}
	num = 0;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		num = num * 10 + (*arg - '0');
		if (((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN)))
			return (false);
		++arg;
	}
	return (true);
}

void	check_duplication(t_data *data, int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				error(data);
			}
			++j;
		}
		++i;
	}
}

void	calculate_rank(int *numbers, int *rank, int size)
{
	int	i;
	int	j;
	int	smaller;

	i = 0;
	while (i < size)
	{
		j = 0;
		smaller = 0;
		while (j < size)
			if (numbers[j++] <= numbers[i])
				smaller++;
		rank[i] = smaller;
		++i;
	}
}

void	free_stack(t_stack *stack)
{
	if (stack->stack)
	{
		free(stack->stack);
		stack->stack = NULL;
	}
}
