/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/18 18:24:46 by skanna           ###   ########.fr       */
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
int	find_position(t_node *list, int value)
{
	t_node	*temp;
	int		position;

	position = 1;
	temp = list;
	while (temp != NULL)
	{
		if (temp->value == value)
			break ;
		position++;
		temp = temp->next;
	}
	return (position);
}

int	find_smallest(t_node *list, int n)
{
	t_node	*temp;
	int		i;
	int		smallest;

	i = 1;
	smallest = INT_MAX;
	temp = list;
	while (temp != NULL && i <= n)
	{
		if (temp->value < smallest)
			smallest = temp->value;
		i++;
		temp = temp->next;
	}
	return (smallest);
}

int	find_sec_smallest(t_node *list, int n, int smallest)
{
	t_node	*temp;
	int		i;
	int		sec_smallest;

	i = 1;
	sec_smallest = INT_MAX;
	temp = list;
	while (temp != NULL && i <= n)
	{
		if (temp->value < sec_smallest && temp->value != smallest)
			sec_smallest = temp->value;
		temp = temp->next;
		i++;
	}
	return (sec_smallest);
}

int	find_biggest(t_node *list, int n)
{
	t_node	*temp;
	int		i;
	int		biggest;

	i = 1;
	biggest = INT_MIN;
	temp = list;
	while (temp != NULL && i <= n)
	{
		if (temp->value > biggest)
			biggest = temp->value;
		temp = temp->next;
		i++;
	}
	return (biggest);
}

int	find_sec_biggest(t_node *list, int n)
{
	t_node	*temp;
	int		i;
	int		position;
	int		biggest;

	i = 1;
	position = 0;
	biggest = INT_MIN;
	temp = list;
	while (temp != NULL && i <= n)
	{
		if (temp->value > biggest)
		{
			biggest = temp->value;
			position = i;
		}
		temp = temp->next;
		i++;
	}
	return (position);
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

