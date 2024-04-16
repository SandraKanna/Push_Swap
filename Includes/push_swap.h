/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:01 by skanna            #+#    #+#             */
/*   Updated: 2024/04/17 01:04:42 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/Includes/libft_extended.h"

typedef struct s_node
{
	int				value;
	int				rank;
	char			*line;
	struct s_node	*next;
}					t_node;

typedef struct s_struct
{
	int				count;
	int				len_bits;
	int				iterations;
	struct s_node	*a;
	struct s_node	*b;
}					t_struct;

char		**check_input(int *elements_count, int argc, char **argv);
t_struct	*init_struct(char **av, int count);

void		push(t_node **stack, int input, int rank, int *err);
void		push_to_stack(t_struct *structure, char c);
void		swap_stack(t_struct *structure, char c);
void		rotate_down_stack(t_struct *structure, char c);
void		rotate_up_stack(t_struct *structure, char c);

void		divide_list(t_struct *structure, int size, int groups);
void		sort_list(t_struct *structure);
void		base_case(t_struct *structure, int size);

void		best_rotation(t_struct *structure, int value, char c);
int			count_nodes(t_node *list);
int			is_stack_sorted(t_node *stack, int n);

int			find_position(t_node *list, int value);
int			find_smallest(t_node *list, int n);
int			find_biggest(t_node *list, int n);

void		free_stack(t_node **stack);
void		free_struct(t_struct *structure);
void		err_handling(t_struct *structure);

#endif
