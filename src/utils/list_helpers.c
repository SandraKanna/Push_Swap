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

// t_node	*find_last(t_node *list)
// {
// 	t_node	*last;

// 	last = list;
// 	if (list)
// 	{
// 		while (last->next != NULL)
// 			last = last->next;
// 	}
// 	return (last);
// }

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
