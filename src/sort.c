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

void	base_case(t_struct *structure, int size)
{
	int	smallest;
	int	biggest;

	if (is_stack_sorted(structure->a, size))
		return ;
	if (size == 2)
		return (swap_stack(structure, 'a'));
	smallest = find_smallest(structure->a, size);
	biggest = find_biggest(structure->a, size);
	if (smallest == structure->a->rank)
	{
		swap_stack(structure, 'a');
		rotate_up_stack(structure, 'a');
	}
	else if (smallest == structure->a->next->rank)
	{
		if (biggest == structure->a->rank)
			rotate_up_stack(structure, 'a');
		else
			swap_stack(structure, 'a');
	}
	else if (smallest == structure->a->next->next->rank)
	{
		if (biggest == structure->a->next->rank)
			rotate_down_stack(structure, 'a');
		else
		{
			swap_stack(structure, 'a');
			rotate_down_stack(structure, 'a');
		}
	}
}

void	sort_list(t_struct *structure)
{
	int	biggest;
	int	sec_big;
	int	temp;

	temp = 0;
	while (structure->b != NULL)
	{
		biggest = find_biggest(structure->b, count_nodes(structure->b));
		sec_big = biggest - 1;
		if (structure->b->rank == biggest)
		{
			push_to_stack(structure, 'a');
			if (temp == 1)
			{
				swap_stack(structure, 'a');
				temp = 0;
			}
		}
		else if (structure->b->rank == sec_big)
		{
			push_to_stack(structure, 'a');
			temp = 1;
		}
		else if (structure->b->next->rank == biggest)
		{
			if (structure->a->rank > structure->a->next->rank)\
				swap_stack(structure, 'c');
			else
				swap_stack(structure, 'b');
		}
		else
			best_rotation(structure, biggest, 'b');
	}
}

void	push_swap(t_struct *structure, int size)
{
	int	initial_groups;

	initial_groups = structure->len_bits - 1;
	if (structure->a && is_stack_sorted(structure->a, size))
		return ;
	if (size <= 3)
		base_case(structure, size);
	else
	{
		divide_list(structure, size, initial_groups);
		// printf("\n--- after divide stack A ---\n");
		// for (t_node *printme = structure->a; printme != NULL; printme = printme->next)
		// 	printf("A: %i\n", printme->rank);
		sort_list(structure);
	}
	// if (is_stack_sorted(structure->a, size)
	// 	&& (count_nodes(structure->a) == structure->count))
	// 	printf("n: %i stack_a is sorted!\n", size);
}
