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

void	base_case_1(t_struct *structure, int size)
{
	int	smallest;
	int	biggest;

	if (size == 2)
		return (swap_stack(structure, 'a'));
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
		if (structure->head_a->rank <= biggest)
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
		// else if (count_nodes(structure->head_a) >= 2 && structure->head_a->next->rank <= biggest)
		// {
		// 	if (count_nodes(structure->head_b) >= 2 && structure->head_b->next->rank > structure->head_b->rank)
		// 		swap_stack(structure, 'c');
		// 	else
		// 		swap_stack(structure, 'a');
		// }
		else
			rotate_up_stack(structure, 'a');
	}
	return (count_nodes(structure->head_a));
}

void	last_division(t_struct *structure, int size)
{
	int	smallest;
	int	position;
	int	move_to_b;

	move_to_b = size - 3;
	printf("\n--- last div ---\n --- stack A ---\n");
	for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
		printf("A: %i\n", printme->rank);
	printf("\n--- stack B ---\n");
	for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
		printf("B: %i\n", printme->rank);
	while (count_nodes(structure->head_a) > 3)
	{
		smallest = find_smallest(structure->head_a, size);
		position = find_position(structure->head_a, smallest);
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



