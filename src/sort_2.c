/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:06:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/11 18:14:02 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	head_1(int next, int prev, int last, t_node **set_list)
{
	int	mid;

	mid = (*set_list)->next->next->rank;
	if (next == 2 || next == 3)
	{
		if (mid == 5 || (mid == 2 && prev == 5))
			return (5);
		if ((next == 2 && mid == 4 && prev != 5)
			|| (next == 3 && mid == 2))
			ra(set_list);
		else
			rra(set_list);
	}
	else if (next == 4 || next == 5)
	{
		if (mid == 4 || ((mid == 3 && last == 5)
				|| (mid == 5 && prev == 3) || (mid == 2 && prev == 5)))
			return (5);
		if (next == 4 && mid == 3)
			ra(set_list);
		else
			sa(set_list);
	}
	return (is_stack_sorted(*set_list));
}

int	head_2(int next, int prev, int last, t_node **set_list)
{
	int	mid;

	mid = (*set_list)->next->next->rank;
	if ((next == 3 && mid == 1 && prev == 5) || (next == 5
			&& ((mid == 1 && last == 3) || (mid == 4 && last == 1))))
		return (5);
	if (next == 1 || next == 5)
	{
		if (next == 5 && mid == 4)
			ra(set_list);
		else
			sa(set_list);
	}
	else if (next == 3 || next == 4)
	{
		if ((next == 4 && mid == 3) || (next == 3 && ((mid == 1)
					|| (last == 1 && mid == 5))))
			ra(set_list);
		else if (next == 4 && mid == 1 && last == 5)
			sa(set_list);
		else
			rra(set_list);
	}
	return (is_stack_sorted(*set_list));
}

int	head_3(int next, int prev, t_node **set_list)
{
	int	mid;

	mid = (*set_list)->next->next->rank;
	if (next == 1 || next == 2)
	{
		if (next == 1 && (mid == 5 || (mid == 2 && prev == 5)))
			return (5);
		if (next == 5 && mid == 4)
			ra(set_list);
		else
			sa(set_list);
	}
	else if (next == 4 || next == 5)
	{
		if ((next == 4 && prev == 5) || (next == 5 && mid == 4))
			ra(set_list);
		else
			rra(set_list);
	}
	return (is_stack_sorted(*set_list));
}

int	head_4(int next, int prev, int last, t_node **set_list)
{
	int	mid;

	mid = (*set_list)->next->next->rank;
	if (next == 1 || next == 5)
	{
		if (next == 1 && prev == 5)
			sa(set_list);
		else if ((next == 1 && last == 3 && prev != 5) || (next == 5
				&& (last == 3 || mid == 3)))
			ra(set_list);
		else
			rra(set_list);
	}
	else if (next == 2 || next == 3)
	{
		if (next == 3 && mid == 2 && last == 5)
			return (5);
		if (next == 2 && mid == 1 && last == 5)
			rra(set_list);
		else
			sa(set_list);
	}
	return (is_stack_sorted(*set_list));
}

int	sort_5(t_struct *structure)
{
	int	next;
	int	prev;
	int	last;
	int	head;

	if (is_stack_sorted(structure->head_a))
		return (1);
	head = structure->head_a->rank;
	next = structure->head_a->next->rank;
	prev = structure->head_a->next->next->next->rank;
	structure->head_a->last = find_last(structure->head_a);
	last = structure->head_a->last->rank;
	if (head == 1)
		return (head_1(next, prev, last, &structure->head_a));
	if (head == 2)
		return (head_2(next, prev, last, &structure->head_a));
	if (head == 3)
		return (head_3(next, prev, &structure->head_a));
	if (head == 4)
		return (head_4(next, prev, last, &structure->head_a));
	if (head == 5)
		return (head_5(next, prev, last, &structure->head_a));
	return (0);
}
