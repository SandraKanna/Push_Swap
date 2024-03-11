/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:06:55 by skanna            #+#    #+#             */
/*   Updated: 2024/02/24 16:22:26 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	tiny_sort(t_struct *structure, int size)
{
	int	head;
	int	mid;

	if (size == 2)
		return (sa(&structure->head_a), 1);
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

int	head_5(int next, int prev, int last, t_node **set_list)
{
	int	mid;

	mid = find_mid_of_set(*set_list)->rank;
	if ((next == 3 && mid == 1 && prev == 4)
		|| (next == 4 && mid == 3 && prev == 2))
		return (5);
	if (next == 1 || next == 2)
	{
		if (last == 4 || (next == 1 && mid == 4 && prev == 2))
			ra(set_list);
		else if (next == 2 && mid == 4 && prev == 1)
			sa(set_list);
		else
			rra(set_list);
	}
	else if (next == 4 || next == 3)
	{
		if (next == 3 && last == 4)
			ra(set_list);
		else if (mid == 2 && prev == 4)
			rra(set_list);
		else
			sa(set_list);
	}
	return (is_stack_sorted(*set_list));
}

