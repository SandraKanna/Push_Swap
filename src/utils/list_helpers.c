/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/28 16:31:48 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_stack_sorted(t_node *stack, int n)
{
	while (stack->next != NULL && n > 0)
	{
		if (stack->rank > stack->next->rank
			|| stack->next->rank - stack->rank != 1)
			return (0);
		n--;
		stack = stack->next;
	}
	return (1);
}

int	count_nodes(t_node *list)
{
	t_node			*current;
	unsigned int	count;

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

int	find_smallest_bit(t_node *list, int column)
{
	t_node	*temp;
	int		cur_bit;
	int		smallest;

	smallest = INT_MAX;
	temp = list;
	while (temp != NULL)
	{
		cur_bit = (temp->rank >> column) & 1;
		if (cur_bit == 1 && temp->rank < smallest)
			smallest = temp->rank;
		temp = temp->next;
	}
	return (smallest);
}

int	find_biggest_bit(t_node *list, int column)
{
	t_node	*temp;
	int		cur_bit;
	int		biggest;

	biggest = INT_MIN;
	temp = list;
	while (temp != NULL)
	{
		cur_bit = (temp->rank >> column) & 1;
		if (cur_bit == 1 && temp->rank > biggest)
			biggest = temp->rank;
		temp = temp->next;
	}
	return (biggest);
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
		if (temp->rank < smallest)
			smallest = temp->rank;
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
		if (temp->rank > biggest)
			biggest = temp->rank;
		temp = temp->next;
		i++;
	}
	return (biggest);
}
