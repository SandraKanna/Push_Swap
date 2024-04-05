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

#include "push_swap.h"

void	tiny_sort(t_struct *structure, int size)
{
	int	smallest;
	int	biggest;

	// printf("\n--- test tiny ---\n");
	if (size == 2)
		return (swap_stack(structure, 'a'), 1);
	smallest = find_smallest(structure->head_a, size);
	biggest = find_biggest(structure->head_a, size);
	if (smallest == structure->head_a->rank)
	{
		swap_stack(structure, 'a');
		rotate_up_stack(structure, 'a');
	}
	else if (smallest == structure->head_a->next->rank)
	{
		if (biggest == structure->head_a->rank)
			rotate_up_stack(structure, 'a');
		else
			swap_stack(structure, 'a');
	}
	else if (smallest == structure->head_a->next->next->rank)
	{
		if (biggest == structure->head_a->next->rank)
			rotate_down_stack(structure, 'a');
		else
		{
			swap_stack(structure, 'a');
			rotate_down_stack(structure, 'a');
		}
	}
}

void	last_iteration(t_struct *structure, int bit_column)
{
	int	holder;
	int	smallest_b;
	int	group0;
	int	count_b;

	count_b = count_nodes(structure->head_b);
	group0 = count_bits(structure->head_b, 0, bit_column, count_b);
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

void	sort_top_stacks(t_struct *structure)
{
	int	biggest_b;
	int	smallest_a;

	smallest_a = find_smallest(structure->head_a, 3);
	biggest_b = find_biggest(structure->head_b, 3);
	if (structure->head_a->rank > structure->head_b->rank)
	{
		if ()
		swap_stack(structure, 'b');
	}
	else
	{
		push_to_stack(structure, 'a');
		if (structure->head_a->rank > structure->head_b->next->rank)
		{
			swap_stack(structure, 'a');
		}
	}

}

void	sort_a(t_struct *structure, int start, int to_sort, int rotations)
{
	int	cur_bit;
	int	move_to_b;

	while ()
	{
		cur_bit = (structure->head_a->rank >> start) & 1;
		if (cur_bit == 0)
		{
			push_to_stack(structure, 'b');
			move_to_b--;
		}
		else
			rotations += do_rotations(structure, 'b', rotations, move_to_b);
	}
}

void	sort_b(t_struct *structure, int start, int to_sort, int rot)
{
	int	cur_bit;
	int	move_to_a;
	int	i;
//sort == 1 radix == len_bit of biggest rank of to_sort elements
//iterations == iterate through each bit of the to_sort elements->rank
	i = to_sort;
	while (i > 0)
	{
		move_to_a = count_bits(structure->head_b, 1, start, to_sort);
		while (move_to_a >= 0)
		{
			cur_bit = (structure->head_b->rank >> start) & 1;
			if (cur_bit == 1)
			{
				push_to_stack(structure, 'a');
				move_to_a--;
			}
			else
				rot += do_rotations(structure, 'b', rot, move_to_a);
		}
		sort_a(structure, ++start, to_sort, rot);
		i--;
	}
}

// void	sort_b(t_struct *structure, int bit_column)
// {
// 	int		holder1;
// 	int		move_to_a;
// 	int		keep_in_b;

// 	if (is_stack_sorted(structure->head_a))
// 		return (last_iteration(structure, bit_column));
// 	holder1 = -1;
// 	move_to_a = count_bits(structure->head_b, 1, bit_column);
// 	keep_in_b = count_bits(structure->head_b, 0, bit_column);
// 	while (structure->head_b != NULL
// 		&& (move_to_a > 0 || (move_to_a == 0 && keep_in_b > 0)))
// 	{
// 		holder1 = (structure->head_b->rank >> bit_column) & 1;
// 		if (holder1 == 1)
// 		{
// 			push_to_stack(structure, 'a');
// 			move_to_a--;
// 		}
// 		else
// 		{
// 			rotate_up_stack(structure, 'b');
// 			keep_in_b--;
// 		}
// 	}

// }


