/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/28 16:43:14 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_rotation(t_struct *structure, int value, char c)
{
	int	position;
	int	size;

	position = find_position(structure->head_a, value);
	size = count_nodes(structure->head_a);
	if (c == 'b')
	{
		position = find_position(structure->head_a, value);
		size = count_nodes(structure->head_b);
	}
	if (position <= size / 2)
		rotate_up_stack(structure, c);
	else
		rotate_down_stack(structure, c);
}

void	last_division(t_struct *structure, int size, int iter)
{
	int	smallest;
	int	position;
	int	move_to_b;

	move_to_b = size - 3;
	structure->batch_size[iter] = move_to_b;
	while (structure->head_a != NULL)
	{
		smallest = find_smallest(structure->head_a, size);
		position = find_position(structure->head_a, smallest);
		if (count_nodes(structure->head_a) == 3)
			break ;
		if (move_to_b > 0)
		{
			if (structure->head_a->rank == smallest)
			{
				push_to_stack(structure, 'b');
				move_to_b--;
			}
			else
				best_rotation(structure, position, 'a');
		}
	}
	size = count_nodes(structure->head_a);
	base_case_1(structure, size);
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
