/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:34:59 by sandra            #+#    #+#             */
/*   Updated: 2024/04/16 22:57:42 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_division(t_struct *structure, int size)
{
	int	smallest;
	int	sec_smallest;
	int	temp;
	int	move_to_b;

	move_to_b = size - 3;
	temp = 0;
	// printf("last division: size: %i\n", size);
	while (count_nodes(structure->a) > 3 && move_to_b > 0)
	{
		smallest = find_smallest(structure->a, count_nodes(structure->a));
		sec_smallest = smallest + 1;
		if (structure->a->rank == smallest)
		{
			push_to_stack(structure, 'b');
			move_to_b--;
			if (temp == 1)
			{
				swap_stack(structure, 'b');
				temp = 0;
			}
		}
		else if (structure->a->rank == sec_smallest
			&& count_nodes(structure->a) > 4)
		{
			push_to_stack(structure, 'b');
			move_to_b--;
			temp = 1;
		}
		else
			rotate_up_stack(structure, 'a');
	}
	size = count_nodes(structure->a);
	base_case(structure, size);
}

int	create_group(t_struct *structure, int size, int group)
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
			// printf("last division condition: size of a: %i\n", count_nodes(structure->a));
			last_division(structure, count_nodes(structure->a));
			break ;
		}
		// printf("test cur top A: %i\n", structure->a->rank);
		if (structure->a->rank <= biggest && structure->a->rank < structure->count - 2)
		{
			push_to_stack(structure, 'b');
			if (structure->b->rank < mid)
			{
				if (structure->a->rank > biggest)
					rotate_up_stack(structure, 'c');
				else
					rotate_up_stack(structure, 'b');
			}
			i++;
		}
		else
			rotate_up_stack(structure, 'a');
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
		// printf("\n--- iter: %i nodes in A: %i---\n", i, count_nodes(structure->a));
		if (is_stack_sorted(structure->a, count_nodes(structure->a)))
			break ;
		create_group(structure, elems_in_group, i);
		i++;
	}
	if (count_nodes(structure->a) > 3)
		last_division(structure, count_nodes(structure->a));
}