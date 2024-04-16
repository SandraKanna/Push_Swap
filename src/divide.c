/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:34:59 by sandra            #+#    #+#             */
/*   Updated: 2024/04/16 19:38:54 by skanna           ###   ########.fr       */
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
	while (count_nodes(structure->head_a) > 3 && move_to_b > 0)
	{
		smallest = find_smallest(structure->head_a, count_nodes(structure->head_a));
		sec_smallest = smallest + 1;
		if (structure->head_a->rank == smallest)
		{
			push_to_stack(structure, 'b');
			move_to_b--;
			if (temp == 1)
			{
				swap_stack(structure, 'b');
				temp = 0;
			}
		}
		else if (structure->head_a->rank == sec_smallest
			&& count_nodes(structure->head_a) > 4)
		{
			push_to_stack(structure, 'b');
			move_to_b--;
			temp = 1;
		}
		else
			rotate_up_stack(structure, 'a');
	}
	size = count_nodes(structure->head_a);
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
	while (i < size && count_nodes(structure->head_b) < (size * group))
	{
		if (count_nodes(structure->head_a) <= 6)
		{
			// printf("last division condition: size of a: %i\n", count_nodes(structure->head_a));
			last_division(structure, count_nodes(structure->head_a));
			break ;
		}
		// printf("test cur top A: %i\n", structure->head_a->rank);
		if (structure->head_a->rank <= biggest && structure->head_a->rank < structure->count - 2)
		{
			push_to_stack(structure, 'b');
			if (structure->head_b->rank < mid)
			{
				if (structure->head_a->rank > biggest)
					rotate_up_stack(structure, 'c');
				else
					rotate_up_stack(structure, 'b');
			}
			i++;
		}
		else
			rotate_up_stack(structure, 'a');
	}
	return (count_nodes(structure->head_a));
}

void	divide_list(t_struct *structure, int size, int groups)
{
	int	elems_in_group;
	int	i;

	elems_in_group = size / groups;
	i = 1;
	while (i <= groups)
	{
		// printf("\n--- iter: %i nodes in A: %i---\n", i, count_nodes(structure->head_a));
		if (is_stack_sorted(structure->head_a, count_nodes(structure->head_a)))
			break ;
		create_group(structure, elems_in_group, i);
		i++;
	}
	if (count_nodes(structure->head_a) > 3)
		last_division(structure, count_nodes(structure->head_a));
}