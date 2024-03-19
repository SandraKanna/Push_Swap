/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:06:55 by skanna            #+#    #+#             */
/*   Updated: 2024/02/24 16:22:26 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../Includes/push_swap.h"
#include "push_swap.h"

int	tiny_sort(t_struct *structure)
{
	int	first;
	int	mid;
	int	last;
	int	size;

	size = count_nodes(structure->head_a);
	if (size == 2)
		return (sa(&structure->head_a), 1);
	first = structure->head_a->value;
	mid = structure->head_a->next->value;
	last = structure->head_a->next->next->value;
	if (first > mid)
	{
		if (first > last && mid < last)
			ra(&structure->head_a);
		else
			sa(&structure->head_a);
	}
	else
		rra(&structure->head_a);
	return (is_stack_sorted(structure->head_a));
}

int	find_position_back(t_node *stack_a, int value)
{
	t_node	*current;
	int		position;

	current = stack_a;
	position = 1;
	if (!current || value < current->value)
		return (1);
	while (current->next != NULL && value > current->next->value)
	{
		position++;
		current = current->next;
	}
	if (current->next == NULL && value > current->value)
		return (position + 1);
	return (position);
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

int	find_group(int count, int rank)
{
	int	group_size;
	int	groups;
	int	i;

	groups = 1;
	i = 3;
	while (i <= count && groups <= 11)
	{
		if (count > i)
			groups++;
		else
			break ;
		i += 3;
	}
	group_size = count / groups;
	i = 1;
	while (i <= groups)
	{
		if (rank <= group_size * i)
			return (i);
		i++;
	}
	return (groups);
}
