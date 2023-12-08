/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:51:08 by fvoicu            #+#    #+#             */
/*   Updated: 2023/12/04 17:32:40 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Lib/Libft/libft.h"
# include "../Lib/Printf/include/ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int		*stack;
	int		top;	
	int		bottom;
	int		size;
}			t_stack;

typedef struct s_data
{
	t_stack			a;
	t_stack			b;
	t_list			*op_list;
}			t_data;

typedef enum e_location
{
	top_a,
	bottom_a,
	top_b,
	bottom_b
}	t_location;

typedef struct s_part
{
	t_location		location;
	int				size;
}				t_part;

typedef struct s_split_dest
{
	t_part			min;
	t_part			mid;
	t_part			max;
}				t_split_dest;

typedef enum e_op
{
	null,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
}	t_op;

/***STACK***/
		/**STACK_MANAGEMENT**/
void			init_data(t_data *data, int ac, char **av);
void			init_stack(t_data *data, t_stack *stack, int size);
bool			is_sorted(t_data *data);
void			free_data(t_data *data);
void			error(t_data *data);

		/**STACK_SETUP**/
void			fill_stack(t_data *data, t_stack *stack, int size, char **arg);
bool			valid_arg(char *arg);
void			check_duplication(t_data *data, int *numbers, int size);
void			calculate_rank(int *numbers, int *rank, int size);
void			free_stack(t_stack *stack);

		/**STACK_UTILS**/
int				prev_index(t_stack *stack, int index);
int				next_index(t_stack *stack, int index);
int				rank_of(t_stack *stack, int n);
int				current_size(t_stack *stack);
bool			is_full(t_stack *stack);

		/**OPERATIONS**/
			/*PUSH*/
void			push(t_stack *src, t_stack *dest);
void			op_pa(t_data *data);
void			op_pb(t_data *data);
void			push_to_stack(t_data *data, \
					t_location src, t_location dest);
			/*RROTATE*/
void			rrotate(t_stack *stack);
void			op_rra(t_data *data);
void			op_rrb(t_data *data);
void			op_rrr(t_data *data);
void			double_rrotate(t_data *data, char stack);
void			rrotate_and_push(t_data *data, t_location src, t_location dest);
			/*ROTATE*/
void			rotate_stack(t_data *data, t_location stack);
void			rotate(t_stack *stack);
void			op_ra(t_data *data);
void			op_rb(t_data *data);
void			op_rr(t_data *data);
			/*SWAP*/
void			swap(t_stack *stack);
void			op_sa(t_data *data);
void			op_sb(t_data *data);
void			op_ss(t_data *data);
void			swap_and_push(t_data *data, char stack);
			/*OP_UTILS*/
void			save_op(t_data *data, enum e_op op);
void			print_op(t_list *head);
const char		*op_to_str(enum e_op op);
enum e_op		op_list(t_list *node);

/***PUSH_SWAP***/
int				main(int ac, char **av);

/***SORT***/
void			sort(t_data *data);
void			sort_three_a(t_data *data);
void			sort_five_a(t_data *data);

	/**SEGMENTED_SORT**/
void			segmented_sort(t_data *data);
void			recursive_segmented_sort(t_data *data, t_part *to_sort);
void			sort_two(t_data *data, t_part *to_sort);
void			sort_one(t_data *data, t_part *to_sort);

	/***SPLIT_SLICE***/
void			divide(t_data *data, t_part *slice, \
						t_split_dest *dest);
void			init_size(t_part *min, t_part *mid, t_part *max);
void			set_split_loc(t_location loc, t_part *min, \
						t_part *mid, t_part *max);
void			triple_part_pivot(t_location loc, int slice_size, \
							int *pivot_1, int *pivot_2);
int				segment_rank(t_data *data, t_part *chunk, int n);
int				segment_max_rank(t_data *data, t_part *chunk);
t_stack			*stack_loc(t_data *data, t_location loc);
void			swap_ints(int *x, int *y);
int				update_index(t_stack *stack, int index, t_location location);

	/***MOVE***/
int				move(t_data *data, t_location src, t_location dest);
void			move_top_a(t_data *data, t_location to);
void			move_top_b(t_data *data, t_location to);
void			move_bottom_a(t_data *data, t_location to);
void			move_bottom_b(t_data *data, t_location to);

	/**OPTIMIZATION: PRELIMINARY SORT**/
void			preliminary_sort(t_data *data, t_part *to_sort);
void			cases(t_data *data, t_part *to_sort);
void			process_top_b(t_data *data, t_part *to_sort);
void			process_bottom_a(t_data *data, t_part *to_sort);
void			process_bottom_b(t_data *data, t_part *to_sort);

	/**SORT_THREE**/
void			sort_three(t_data *data, t_part *to_sort);
void			three_top_a(t_data *data, t_part *to_sort, t_stack *stack,
					int max);
void			three_top_b(t_data *data, t_part *to_sort, \
							t_stack *stack, int max);
void			three_bottom_a(t_data *data, t_part *to_sort, \
							t_stack *stack, int max);
void			three_bottom_b(t_data *data, t_part *to_sort, \
							t_stack *stack, int max);

	/**FAST_SORT**/
void			divide_reduction(t_data *data, t_part *max);
bool			a_part_sort(t_data *data, int src);
bool			is_consecutive(int a, int b, int c, int d);
void			sort_three_ints(int *a, int *b, int *c);
int				get_start_index(t_stack *a, int from);

#endif