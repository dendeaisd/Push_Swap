/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:20:20 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/08 02:37:23 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	do_op(t_data *data, char *op_str)
{
	if (ft_strncmp(op_str, "sa\n", 3) == 0)
		op_sa(data);
	else if (ft_strncmp(op_str, "sb\n", 3) == 0)
		op_sb(data);
	else if (ft_strncmp(op_str, "ss\n", 3) == 0)
		op_ss(data);
	else if (ft_strncmp(op_str, "pa\n", 3) == 0)
		op_pa(data);
	else if (ft_strncmp(op_str, "pb\n", 3) == 0)
		op_pb(data);
	else if (ft_strncmp(op_str, "ra\n", 3) == 0)
		op_ra(data);
	else if (ft_strncmp(op_str, "rb\n", 3) == 0)
		op_rb(data);
	else if (ft_strncmp(op_str, "rr\n", 3) == 0)
		op_rr(data);
	else if (ft_strncmp(op_str, "rra\n", 4) == 0)
		op_rra(data);
	else if (ft_strncmp(op_str, "rrb\n", 4) == 0)
		op_rrb(data);
	else if (ft_strncmp(op_str, "rrr\n", 4) == 0)
		op_rrr(data);
	else
		return (0);
	return (1);
}

static void	print_result(t_data *data)
{
	if (is_sorted(data) && data->b.stack[0] == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

static void	read_and_execute_operations(t_data *data)
{
	char	*op_str;

	op_str = get_next_line(0);
	while ((op_str) != NULL)
	{
		if (!do_op(data, op_str))
		{
			free(op_str);
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		free(op_str);
		op_str = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**og_av;

	og_av = NULL;
	if (ac == 2 && av[1][0] != '\0')
	{
		av = ft_split(av[1], ' ');
		og_av = av;
		ac = 0;
		while (av[ac])
			++(ac);
	}
	else
	{
		--(ac);
		++(av);
	}
	if (ac == 0 || (ac == 1 && av[0][0] == '\0'))
		exit(EXIT_SUCCESS);
	init_data(&data, ac, av);
	read_and_execute_operations(&data);
	print_result(&data);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
