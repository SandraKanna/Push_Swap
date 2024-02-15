/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:01 by skanna            #+#    #+#             */
/*   Updated: 2024/02/15 18:21:15 by skanna           ###   ########.fr       */
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

//static: for test
int		is_signed_nbr(char *str);//to review
int		has_duplicates(int ac, int *input);
//utils
char	**parse_args(int *ac, int argc, char **av);
int		check_errors(int ac, char **av);
// size_t	ft_strlen(const char *str); libft
//char	*ft_vide(void); libft
//char	*ft_substr(char const *s, unsigned int start, size_t len); libft
// char	**ft_split(char const *s, char c); libft
int		do_atoi(const char *str, int *error); //to review, prioritize libft
//clean strings
//void	free_args(char **av); libft

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

t_node	*initialize_stack_a(char **av, int ac);
t_node	*initialize_stack_a2(char **av, int ac);
//core
void	push(t_node **stack, int input);
void	push2(t_node **head, int input);
int		pop(t_node **stack);
int		pop2(t_node **stack);
void	swap(t_node	**stack);
void	swap2(t_node	**stack);
void	rotate_up(t_node **stack);
void	rotate_down(t_node **stack);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node *stack);
void	push_swap(t_node **stack_a);
//clean nodes
void	free_stack(t_node **stack);

#endif