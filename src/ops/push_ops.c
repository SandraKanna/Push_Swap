/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/03/15 10:45:08 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b, int *err)
{
	int	rank;
	int	value;

	if ((*stack_b == NULL) | (stack_b == NULL))
		return ;
	rank = (*stack_b)->rank;
	value = pop(stack_b);
	push(stack_a, value, rank, err);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b, int *err)
{
	int	rank;
	int	value;

	if ((*stack_a == NULL) | (stack_a == NULL))
		return ;
	rank = (*stack_a)->rank;
	value = pop(stack_a);
	push(stack_b, value, rank, err);
	write(1, "pb\n", 3);
	return ;
}

