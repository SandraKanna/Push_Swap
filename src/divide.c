/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:34:59 by sandra            #+#    #+#             */
/*   Updated: 2024/04/17 14:20:09 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	div_helper(t_struct *structure, int small, int to_move, int *swap)
{
	int	sec_smallest;

	sec_smallest = small - 1;
	if (structure->a->rank == small)
	{
		push_to_stack(structure, 'b');
		to_move--;
		if (*swap == 1)
		{
			swap_stack(structure, 'b');
			*swap = 0;
		}
	}
	else if (structure->a->rank == sec_smallest
		&& count_nodes(structure->a) > 4)
	{
		push_to_stack(structure, 'b');
		to_move--;
		*swap = 1;
	}
	else
		rotate_up_stack(structure, 'a');
	return (to_move);
}

static void	last_division(t_struct *structure, int size)
{
	int	smallest;
	int	swap;
	int	move_to_b;

	move_to_b = size - 3;
	swap = 0;
	while (count_nodes(structure->a) > 3 && move_to_b > 0)
	{
		smallest = find_smallest(structure->a, count_nodes(structure->a));
		move_to_b = div_helper(structure, smallest, move_to_b, &swap);
	}
	size = count_nodes(structure->a);
	base_case_1(structure, size);
}

static int	create_helper(t_struct *structure, int big, int mid, int i)
{
	if (structure->a->rank <= big
		&& structure->a->rank < structure->count - 2)
	{
		push_to_stack(structure, 'b');
		if (structure->b->rank < mid)
		{
			if (structure->a->rank > big)
				rotate_up_stack(structure, 'c');
			else
				rotate_up_stack(structure, 'b');
		}
		i++;
	}
	else
		rotate_up_stack(structure, 'a');
	return (i);
}

static int	create_group(t_struct *structure, int size, int group)
{
	int	biggest;
	int	mid;
	int	i;

	biggest = size * group;
	mid = (biggest - (size / 2));
	i = 0;
	while (i < size && count_nodes(structure->b) < (size * group))
	{
		if (count_nodes(structure->a) <= 6)
		{
			last_division(structure, count_nodes(structure->a));
			break ;
		}
		i = create_helper(structure, biggest, mid, i);
	}
	return (count_nodes(structure->a));
}

void	divide_list(t_struct *structure, int size, int groups)
{
	int	elems_in_group;
	int	i;

	elems_in_group = size / groups;
	i = 1;
	while (i <= groups)
	{
		if (is_stack_sorted(structure->a, count_nodes(structure->a)))
			break ;
		create_group(structure, elems_in_group, i);
		i++;
	}
	if (count_nodes(structure->a) > 3)
		last_division(structure, count_nodes(structure->a));
}
