/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:01 by skanna            #+#    #+#             */
/*   Updated: 2024/04/16 23:26:39 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "push_swap.h"

void	push(t_node **stack, int input, int rank, int *err);
int		pop(t_node **stack);
void	pa(t_node **stack_a, t_node **stack_b, int *err);
void	pb(t_node **stack_a, t_node **stack_b, int *err);
void	swap(t_node	**stack);
void	rotate_up(t_node **stack);
void	rotate_down(t_node **stack);


#endif
