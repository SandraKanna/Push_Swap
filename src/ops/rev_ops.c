/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/04/16 22:56:28 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

void	rotate_down(t_node **stack)
{
	t_node	*temp;
	t_node	*new_first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	new_first = temp->next;
	new_first->next = *stack;
	temp->next = NULL;
	*stack = new_first;
}

void	rotate_down_stack(t_struct *structure, char c)
{
	if (c == 'a')
	{
		rotate_down(&structure->a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		rotate_down(&structure->b);
		write(1, "rrb\n", 4);
	}
	else
	{
		rotate_down(&structure->a);
		rotate_down(&structure->b);
		write(1, "rrr\n", 4);
	}
}

