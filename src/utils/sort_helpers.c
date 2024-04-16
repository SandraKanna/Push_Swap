/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/04/17 01:04:50 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_rotation(t_struct *structure, int value, char c)
{
	int	position;
	int	size;

	if (c == 'a')
	{
		position = find_position(structure->a, value);
		size = count_nodes(structure->a);
	}
	if (c == 'b')
	{
		position = find_position(structure->b, value);
		size = count_nodes(structure->b);
	}
	if (position <= size / 2)
		rotate_up_stack(structure, c);
	else
		rotate_down_stack(structure, c);
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

