/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:50:07 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/03 13:52:27 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	save_op(t_data *data, t_op op)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)op);
	if (!new)
	{
		error(data);
		return ;
	}
	ft_lstadd_back(&data->op_list, new);
}

void	print_op(t_list *head)
{
	t_list		*current;
	const char	*op_str;

	current = head;
	while (current)
	{
		op_str = op_to_str(op_list(current));
		ft_printf("%s\n", op_str);
		current = current->next;
	}
}

const char	*op_to_str(t_op op)
{
	static const char	*strings[] = {
		"null", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr", "sa", "sb", "ss"
	};

	return (strings[op]);
}

t_op	op_list(t_list *node)
{
	return ((t_op)(uintptr_t)node->content);
}
