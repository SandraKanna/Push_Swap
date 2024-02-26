/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/02/26 15:55:47 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b, int *err)
{
	int	value;

	if ((*stack_b == NULL) | (stack_b == NULL))
		return ;
	value = pop(stack_b);
	push(stack_a, value, err);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b, int *err)
{
	int	value;

	if ((*stack_a == NULL) | (stack_a == NULL))
		return ;
	value = pop(stack_a);
	push(stack_b, value, err);
	write(1, "pb\n", 3);
	return ;
}

