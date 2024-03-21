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
		if (structure->head_a == NULL || structure->head_a->next == NULL)
			return ;
		swap(&structure->head_a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		if (structure->head_b == NULL || (structure->head_b->next == NULL))
			return ;
		swap(&structure->head_b);
		write(1, "sb\n", 3);
	}
	else
	{
		if (structure->head_b == NULL || structure->head_b->next == NULL
			|| structure->head_a == NULL || structure->head_a->next == NULL)
			return ;
		swap(&structure->head_a);
		swap(&structure->head_b);
		write(1, "ss\n", 3);
	}
}
