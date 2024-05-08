/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/04/17 14:22:38 by skanna           ###   ########.fr       */
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

static int	case2_help(t_struct *structure, int move, int small, int count)
{
	int	position;

	position = find_position(structure->a, small);
	if (move > 0)
	{
		if (structure->a->rank == small)
		{
			push_to_stack(structure, 'b');
			move--;
		}
		else if (position <= count / 2)
			rotate_up_stack(structure, 'a');
		else
			rotate_down_stack(structure, 'a');
	}
	return (move);
}

void	base_case_2(t_struct *structure, int size)
{
	int	smallest;
	int	move_to_b;
	int	remainder_a;

	if (size <= 3)
		return (base_case_1(structure, size));
	move_to_b = size - 3;
	while (structure->a != NULL)
	{
		smallest = find_smallest(structure->a, size);
		if (move_to_b > 0)
			move_to_b = case2_help(structure, move_to_b, smallest, size);
		remainder_a = count_nodes(structure->a);
		if (remainder_a <= 3)
			break ;
	}
	if (remainder_a <= 3 && !is_stack_sorted(structure->a, remainder_a))
		base_case_1(structure, remainder_a);
	while (structure->b != NULL)
		push_to_stack(structure, 'a');
	return ;
}
