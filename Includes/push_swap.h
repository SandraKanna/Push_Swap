/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:01 by skanna            #+#    #+#             */
/*   Updated: 2024/03/18 18:22:06 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/Includes/libft_extended.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*last;
}					t_node;

typedef struct s_struct
{
	int				count;
	struct s_node	*head_a;
	struct s_node	*head_b;
}					t_struct;

//params checks
char	**parse_args(int *count, int ac, char **av);
int		check_errors(int int_count, char **int_list);
int		has_duplicates(int ac, int *input);

//ops
void	push(t_node **stack, int input, int rank, int *err);
int		pop(t_node **stack);
void	swap(t_node	**stack);
void	rotate_up(t_node **stack);
void	rotate_down(t_node **stack);
void	pa(t_node **stack_a, t_node **stack_b, int *err);
void	pb(t_node **stack_a, t_node **stack_b, int *err);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

//clean nodes
void	free_stack(t_node **stack);
void	free_struct(t_struct *structure);
void	free_b(t_node ***b);
void	err_handling(t_struct *structure);

//core

int		is_stack_sorted(t_node *stack);
void	push_sort_b(t_struct *structure, int group);
int		tiny_sort(t_struct *structure);
int		sort_in_a(t_struct *structure, int size);
int		head_5(int next, int prev, int last, t_node **set_list);
int		sort_5(t_struct *structure);
void	push_swap(t_struct *structure, int size);
t_node	*find_last(t_node *list);
int		count_nodes(t_node *list);
void	rank_elems(t_node *list);
int		quadrant(int size, int position);
int		find_position(t_node *list, int value);
int		find_smallest(t_node *list, int n);
int		find_sec_smallest(t_node *list, int n, int smallest);
int		find_biggest(t_node *list, int n);
int		find_group(int count, int rank);
t_struct	*init_struct(char **av, int count);

#endif