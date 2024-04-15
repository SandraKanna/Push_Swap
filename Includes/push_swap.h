/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:01 by skanna            #+#    #+#             */
/*   Updated: 2024/04/15 23:41:28 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/Includes/libft_extended.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_struct
{
	int				count;
	int				len_bits;
	int				iterations;
	// int				*batch_size;
	struct s_node	*head_a;
	struct s_node	*head_b;
}					t_struct;

//input checks
char		**parse_args(int *count, int ac, char **av);
int			check_errors(int int_count, char **int_list);
int			has_duplicates(int ac, int *input);

//structure initialization
t_struct	*init_struct(char **av, int count);
int			get_bit_len(int n);
// int			init_batch(t_struct *structure);
int			create_group(t_struct *structure, int size, int group);
// void		rank_elems(t_node *list);

//ops
void		push(t_node **stack, int input, int rank, int *err);
void		push_to_stack(t_struct *structure, char c);
void		swap_stack(t_struct *structure, char c);
void		rotate_down_stack(t_struct *structure, char c);
void		rotate_up_stack(t_struct *structure, char c);

//core
void		push_swap(t_struct *structure, int size);
void		divide_list(t_struct *structure, int size, int groups);
void		sort_list(t_struct *structure);
void		base_case(t_struct *structure, int size);

//sort helpers
void		best_rotation(t_struct *structure, int value, char c);
// void		last_division(t_struct *structure, int size);
int			count_nodes(t_node *list);
int			is_stack_sorted(t_node *stack, int n);

//find
// t_node		*find_last(t_node *list);
int			find_position(t_node *list, int value);
int			find_smallest(t_node *list, int n);
int			find_sec_smallest(t_node *list, int n, int smallest);
int			find_biggest(t_node *list, int n);


//clean
void		free_stack(t_node **stack);
void		free_struct(t_struct *structure);
void		err_handling(t_struct *structure);

#endif
