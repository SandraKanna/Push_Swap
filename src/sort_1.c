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

void	sort_b(t_struct *structure, int mid)
{
	t_node	*b;
	t_node	*a;

	b = structure->head_b;
	a = structure->head_a;
	if ((b != NULL && b->next != NULL) && b->value < b->next->value)
	{
		b->last = find_last(b);
		if (b->value > b->last->value)
		{
			if (a->rank > mid && a->rank > a->next->rank)
				ss(&a, &b);
			else
				sb(&b);
		}
		else
		{
			if (b->value > b->last->value)
				rr(&a, &b);
			else
				rb(&structure->head_a);
		}
	}
}

int	tiny_sort(t_struct *structure)
{
	int	first;
	int	mid;
	int	last;
	int	size;

	size = count_nodes(structure->head_a);
	if (size == 2)
		return (sa(&structure->head_a), 1);
	first = structure->head_a->value;
	mid = structure->head_a->next->value;
	last = structure->head_a->next->next->value;
	if (first > mid)
	{
		if (first > last && mid < last)
			ra(&structure->head_a);
		else
			sa(&structure->head_a);
	}
	else
		rra(&structure->head_a);
	return (is_stack_sorted(structure->head_a));
}

int	head_5(int next, int prev, int last, t_node **set_list)
{
	int	mid;

	mid = (*set_list)->next->next->rank;
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

