/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/11 19:01:27 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

t_node	*find_last(t_node *list)
{
	t_node	*last;

	last = list;
	if (list)
	{
		while (last->next != NULL)
		last = last->next;
	}
	return (last);
}

t_node	*find_prev_to_last(t_node *list)
{
	t_node	*prev_to_last;

	prev_to_last = list;
	if (list && list->next != NULL && list->next->next != NULL)
	{
		while (prev_to_last->next->next != NULL)
			prev_to_last = prev_to_last->next;
	}
	return (prev_to_last);
}

t_node	*find_mid_of_set(t_node *list)
{
	t_node	*middle;

	middle = NULL;
	if (list && list->next && list->next->next != NULL)
		middle = list->next->next;
	return (middle);
}

int	is_stack_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	update_order(t_node **list)
{
	t_node	*mid;
	t_node	*prev;
	t_node	*last;

	mid = find_mid_of_set(*list);
	(*list)->middle = mid;
	last = find_last(*list);
	(*list)->last = last;
	prev = find_prev_to_last(*list);
	(*list)->prev = prev;
}
// t_node	*find_middle(t_node *list)
// {
// 	t_node	*middle;
// 	t_node	*move;

// 	middle = list;
// 	move = list->next;
// 	while (move != NULL && move->next != NULL)
// 	{
// 		middle = middle->next;
// 		move = move->next;
// 	}
// 	return (middle);
// }

// int	find_smallest(t_node *list, int n)
// {
// 	t_node	*temp;
// 	int		i;
// 	int		smallest;

// 	i = 0;
// 	smallest = INT_MAX;
// 	temp = list->next;
// 	while (temp != NULL && i < n)
// 	{
// 		if (temp->value < smallest)
// 			smallest = temp->value;
// 		temp = temp->next;
// 		i++;
// 	}
// 	return (smallest);
// }