/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/04/16 22:56:45 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

void	rotate_up(t_node **stack)
{
	t_node	*temp;
	t_node	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}

void	rotate_up_stack(t_struct *structure, char c)
{
	if (c == 'a')
	{
		rotate_up(&structure->a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		rotate_up(&structure->b);
		write(1, "rb\n", 3);
	}
	else
	{
		rotate_up(&structure->a);
		rotate_up(&structure->b);
		write(1, "rr\n", 3);
	}
}
