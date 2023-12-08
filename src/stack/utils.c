/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:50:23 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 07:44:59 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	prev_index(t_stack *stack, int index)
{
	if (current_size(stack) == 0)
		return (index);
	return ((index - 1 + stack->size) % stack->size);
}

int	next_index(t_stack *stack, int index)
{
	if (current_size(stack) == 0)
		return (index);
	return ((index + 1) % stack->size);
}

int	rank_of(t_stack *stack, int n)
{
	int	i;

	i = stack->top;
	while (--n > 0)
		i = next_index(stack, i);
	return (stack->stack[i]);
}

int	current_size(t_stack *stack)
{
	if (stack->top == stack->bottom && stack->stack[stack->top] == 0)
		return (0);
	if (stack->top <= stack->bottom)
		return (stack->bottom - stack->top + 1);
	else
		return ((stack->size - stack->top) + (stack->bottom + 1));
}

bool	is_full(t_stack *stack)
{
	return (stack->size == current_size(stack));
}
