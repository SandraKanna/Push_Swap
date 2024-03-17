/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/15 10:45:43 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

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

int	count_nodes(t_node *list)
{
	t_node	*current;
	int		count;

	if (!list)
		return (0);
	count = 0;
	current = list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	find_smallest(t_node *list, int n)
{
	t_node	*temp;
	int		i;
	int		steps;
	int		smallest;

	i = 0;
	steps = 0;
	smallest = INT_MAX;
	temp = list->next;
	while (temp != NULL && i < n)
	{
		if (temp->value < smallest)
		{
			smallest = temp->value;
			steps++;
		}
		temp = temp->next;
		i++;
	}
	return (steps);
	// return (smallest);
}

int	find_biggest(t_node *list, int n)
{
	t_node	*temp;
	int		i;
	int		steps;
	int		biggest;

	i = 0;
	steps = 0;
	biggest = INT_MIN;
	temp = list->next;
	while (temp != NULL && i < n)
	{
		if (temp->value > biggest)
		{
			biggest = temp->value;
			steps++;
		}
		temp = temp->next;
		i++;
	}
	return (steps);
	//return (biggest);
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

