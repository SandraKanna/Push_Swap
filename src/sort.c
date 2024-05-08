/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:06:55 by skanna            #+#    #+#             */
/*   Updated: 2024/02/24 16:22:26 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	base_case_helper(t_struct *structure, int smallest, int biggest)
{
	if (smallest == structure->a->next->rank)
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

void	base_case_1(t_struct *structure, int size)
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
	else
		base_case_helper(structure, smallest, biggest);
}

static void	sort_helper(t_struct *structure, int big, int sec_big, int *swap)
{
	if (structure->b->rank == big)
	{
		push_to_stack(structure, 'a');
		if (*swap == 1)
		{
			swap_stack(structure, 'a');
			*swap = 0;
		}
	}
	else if (structure->b->rank == sec_big)
	{
		push_to_stack(structure, 'a');
		*swap = 1;
	}
	else if (structure->b->next->rank == big)
	{
		if (structure->a->rank > structure->a->next->rank)
			swap_stack(structure, 'c');
		else
			swap_stack(structure, 'b');
	}
	else
		best_rotation(structure, big, 'b');
}

void	sort_list(t_struct *structure)
{
	int	biggest;
	int	sec_big;
	int	swap;

	swap = 0;
	while (structure->b != NULL)
	{
		biggest = find_biggest(structure->b, count_nodes(structure->b));
		sec_big = biggest - 1;
		sort_helper(structure, biggest, sec_big, &swap);
	}
}
