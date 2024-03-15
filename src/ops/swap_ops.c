/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/03/15 10:45:24 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

void	sa(t_node **stack)
{
	//Do nothing if there is only one or no elements: if node1 or node 2 == NULL
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack)
{
	//Do nothing if there is only one or no elements: if node1 or node 2 == NULL
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a == NULL || (*stack_a)->next == NULL) ||
		(*stack_b == NULL || (*stack_b)->next == NULL))
		return ;
	//ss: sa and sb at the same time
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

