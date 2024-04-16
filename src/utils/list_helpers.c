/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/04/17 00:33:31 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_position(t_node *list, int rank)
{
	t_node	*temp;
	int		position;

	position = 1;
	temp = list;
	while (temp != NULL)
	{
		if (temp->rank == rank)
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
		if (temp->rank < smallest)
			smallest = temp->rank;
		i++;
		temp = temp->next;
	}
	return (smallest);
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
