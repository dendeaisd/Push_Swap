/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:48:49 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 11:47:38 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	char	**og_av;

	og_av = NULL;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		og_av = av;
		ac = 0;
		while (av[ac])
			++ac;
	}
	else
	{
		--ac;
		++av;
	}
	init_data(&data, ac, av);
	sort(&data);
	print_op(data.op_list);
	free_data(&data);
	if (og_av)
		fv_free_array(og_av);
	exit(EXIT_SUCCESS);
}
