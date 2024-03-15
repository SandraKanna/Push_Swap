/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/03/15 10:45:13 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

void	rra(t_node **stack_a)
{
	rotate_down(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	//rrb (reverse rotate b): Shift down all elements of stack b by 1.
	//The last element becomes the first one.
	rotate_down(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	//rrr : rra and rrb at the same time.
	rotate_down(stack_a);
	rotate_down(stack_b);
	write(1, "rrr\n", 4);
}

