/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:01 by skanna            #+#    #+#             */
/*   Updated: 2024/02/22 17:17:28 by skanna           ###   ########.fr       */
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


//params checks
char	**parse_args(int *count, int ac, char **av);
int		check_errors(int int_count, char **int_list);
int		has_duplicates(int ac, int *input);

typedef struct s_node
{
	int				value;
	// int				*index;
	struct s_node	*next;
}					t_node;

typedef struct s_struct
{
	int				count;
	int				*set;
	int				*tags;
	int				sorted;
	//int				head_index;
	struct s_node	*head;
}					t_struct;

//init
t_struct	*initialize_a(char **av, int count);

t_node		*find_last(t_node *list);
t_node		*find_prev_last(t_node *list);
void	list_init(t_struct *stack_a, int input, int *err);
void	get_set(t_struct *structure, int set_size);
// void		push_bottom(t_node **stack, int input, int *err);

//ops
void		push_top(t_node **stack, int input, int *err);
int			pop(t_node **stack);
void		swap(t_node	**stack);
void		rotate_up(t_node **stack);
void		rotate_down(t_node **stack);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);
void		sa(t_node **stack);
void		sb(t_node **stack);
void		ss(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);
int		stack_sorted(t_node *stack);
int		index_sorted(int *array, int len);
void		push_swap(t_struct *structure);
//clean nodes
void		free_stack(t_node **stack);
void		free_struct(t_struct *structure);
void		err_handling(t_struct *structure);
//core


#endif