/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:06:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/05 17:30:50 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	tiny_sort_a(t_struct *structure, int size)
{
	int	head;
	int	mid;

	if (size == 2)
		return (sa(&structure->head_a), 1);
	update_order(structure, 'a');
	update_rank_a(structure->head_a, size);
	head = structure->head_a->rank;
	mid = structure->head_a->next->rank;
	if (head <= 2)
	{
		if (mid == 1)
			sa(&structure->head_a);
		else
			rra(&structure->head_a);
	}
	else if (head == 3)
	{
		if (mid == 1)
			ra(&structure->head_a);
		else
			sa(&structure->head_a);
	}
	return (is_stack_sorted(structure->head_a));
}