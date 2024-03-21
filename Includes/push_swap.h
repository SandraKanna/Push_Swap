/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:01 by skanna            #+#    #+#             */
/*   Updated: 2024/03/19 18:55:50 by skanna           ###   ########.fr       */
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
	int				*bit;
	struct s_node	*next;
	struct s_node	*last;
}					t_node;

typedef struct s_struct
{
	int	count;
	struct s_node	*head_a;
	struct s_node	*head_b;
}					t_struct;

//params checks
char		**parse_args(int *count, int ac, char **av);
int			check_errors(int int_count, char **int_list);
int			has_duplicates(int ac, int *input);

t_struct	*init_struct(char **av, int count);
void		rank_elems(t_node *list);

//ops
void		push(t_node **stack, int input, int rank, int *err);
void		push_to_stack(t_struct *structure, char c);
void		swap_stack(t_struct *structure, char c);
void		rotate_down_stack(t_struct *structure, char c);
void		rotate_up_stack(t_struct *structure, char c);

//core
void		push_swap(t_struct *structure, int size);
int			tiny_sort(t_struct *structure);

int	count_nodes(t_node *list);
int			is_stack_sorted(t_node *stack);
t_node		*find_last(t_node *list);
int			find_position(t_node *list, int value);
int			find_position_back(t_node *stack_a, int value);
int			find_smallest(t_node *list, int n);
int			find_sec_smallest(t_node *list, int n, int smallest);
// int		find_biggest(t_node *list, int n);
int			find_group(int count, int rank);

//clean nodes
void		free_stack(t_node **stack);
void		free_struct(t_struct *structure);
void		err_handling(t_struct *structure);

#endif