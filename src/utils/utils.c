/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/02/21 16:22:26 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

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

int	find_smallest(t_node *list, int n)
{
	t_node	*temp;
	int		i;
	int		smallest;

	i = 0;
	smallest = INT_MAX;
	temp = list->next;
	while (temp != NULL && i < n)
	{
		if (temp->value < smallest)
			smallest = temp->value;
		temp = temp->next;
		i++;
	}
	return (smallest);
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
