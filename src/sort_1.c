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
		return (swap_stack(structure, 'a'), 1);
	first = structure->head_a->value;
	mid = structure->head_a->next->value;
	last = structure->head_a->next->next->value;
	if (first > mid)
	{
		if (first > last && mid < last)
			rotate_up_stack(structure, 'a');
		else
			swap_stack(structure, 'a');
	}
	else
		rotate_down_stack(structure, 'a');
	return (is_stack_sorted(structure->head_a));
}

void	last_iteration(t_struct *structure, int bit_column)
{
	int	holder;
	int	smallest_b;
	int group0;

	group0 = count_bits(structure->head_b, 0, bit_column);
	while (structure->head_b != NULL)
	{
		holder = (structure->head_b->rank >> bit_column) & 1;
		if (group0 > 0)
		{
			if (holder == 0)
			{
				push_to_stack(structure, 'a');
				group0--;
			}
			else
				rotate_up_stack(structure, 'b');
		}
		else
		{
			smallest_b = find_smallest_bit(structure->head_b, bit_column);
			if (structure->head_b->rank == smallest_b)
			{
				push_to_stack(structure, 'a');
				rotate_up_stack(structure, 'a');
			}
			else
				rotate_down_stack(structure, 'b');
		}
	}
}

void	sort_b(t_struct *structure, int bit_column)
{
	int		holder1;
	int		move_to_a;
	int		keep_in_b;

	if (is_stack_sorted(structure->head_a))
		return (last_iteration(structure, bit_column));
	holder1 = -1;
	move_to_a = count_bits(structure->head_b, 1, bit_column);
	keep_in_b = count_bits(structure->head_b, 0, bit_column);
	while (structure->head_b != NULL
		&& (move_to_a > 0 || (move_to_a == 0 && keep_in_b > 0)))
	{
		holder1 = (structure->head_b->rank >> bit_column) & 1;
		if (holder1 == 1)
		{
			push_to_stack(structure, 'a');
			move_to_a--;
		}
		else
		{
			rotate_up_stack(structure, 'b');
			keep_in_b--;
		}
	}

}


