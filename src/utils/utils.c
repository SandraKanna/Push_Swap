/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/02/19 19:57:10 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

static void	push_bottom(t_node **stack, int input, int *err)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
	{
		*err = 1;
		return ;
	}
	new_node->value = input;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		last = find_last(*stack);
		last->next = new_node;
	}
}

void	list_init(t_node **stack_a, int input, int *err)
{
	t_node	*last;

	if (stack_a != NULL)
	{
		if (is_smaller(input, (*stack_a)->value)) //put smallest at the top of A so head_index = a
			push_top(stack_a, input, err);

	}
	push_bottom(stack_a, input, &err);
}

t_node	*find_last(t_node *list)
{
	t_node	*last;

	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_node	*find_prev_last(t_node *list)
{
	t_node	*prev;

	prev = list;
	while (prev->next->next != NULL)
		prev = prev->next;
	return (prev);
}

// int	find_middle_value(t_node **list)
// {
// 	t_node	*middle;
// 	t_node	*move;

// 	middle = *list;
// 	move = (*list)->next;
// 	while (move != NULL && move->next != NULL)
// 	{
// 		middle = middle->next;
// 		move = move->next;
// 	}
// 	return (middle->value);
// }
