/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/02/15 17:35:43 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	int	value;
	//Do nothing if b is empty.
	if (*stack_b == NULL | stack_b == NULL)
		return ;
	//pa (push a): Take the first element at the top of b and put it at the top of a.
	value = pop(stack_b);
	push(stack_a, value, 0);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	int	value;
	//Do nothing if a is empty.
	if (*stack_a == NULL | stack_a == NULL)
		return ;
	//pb (push b): Take the first element at the top of a and put it at the top of b.
	value = pop(stack_a);
	push(stack_b, value, 0);
	write(1, "pb\n", 3);
	return ;
}

