/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/02/15 17:35:51 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	ra(t_node **stack_a)
{
	//(rotate a): Shift up all elements of stack a by 1.
	//The first element becomes the last one.
	rotate_up(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	//rb (rotate b): Shift up all elements of stack b by 1.
	//The first element becomes the last one.
	rotate_up(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	//rr : ra and rb at the same time.
	rotate_up(stack_a);
	rotate_up(stack_b);
	write(1, "rr\n", 3);
}

