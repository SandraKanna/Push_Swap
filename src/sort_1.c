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

	// printf("\n--- test tiny ---\n");
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


