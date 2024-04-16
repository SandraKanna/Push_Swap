/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/04/16 23:20:13 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

void	swap(t_node	**stack)
{
	t_node	*temp1;
	t_node	*new_first;

	temp1 = *stack;
	new_first = temp1->next;
	temp1->next = new_first->next;
	new_first->next = temp1;
	*stack = new_first;
}

void	swap_stack(t_struct *structure, char c)
{
	if (c == 'a')
	{
		if (structure->a == NULL || structure->a->next == NULL)
			return ;
		swap(&structure->a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		if (structure->b == NULL || (structure->b->next == NULL))
			return ;
		swap(&structure->b);
		write(1, "sb\n", 3);
	}
	else
	{
		if (structure->b == NULL || structure->b->next == NULL
			|| structure->a == NULL || structure->a->next == NULL)
			return ;
		swap(&structure->a);
		swap(&structure->b);
		write(1, "ss\n", 3);
	}
}
