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

#include "../../Includes/push_swap.h"

static int	head_1(int next, int last, int count, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if (next < mid)
	{
		if (mid < prev)
			return (rra(set_list), 0);
	}
	if (count == 4 && (next == 2 || last == count || prev == count - 1))
		ra(set_list);
	else if (count == 4 && (next == 3 && last == 2))
		rra(set_list);
	else if (next == count && last == count - 1)
		sa(set_list);
	return (is_stack_sorted(*set_list));
}

static int	head_2(int next, int last, int count, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if (next < mid && mid < prev)
	{
		printf ("prev rank: %i\n", prev);
		printf ("last rank: %i\n", last);
		if (prev < last)
			return (sa(set_list), 0);
		// else
		// 	return (rra(set_list), 0);
	}
	if ((next == count - 1 && last == count) || (next == count && last == 1)
		|| (next == 1 && last == count - 1))
		ra(set_list);
	else if (count == 4 && ((next == 1 && last == count) 
		|| (next == 1 && last == count - 1)))
		sa(set_list);
	else
		rra(set_list);
	printf ("is sorted: %i\n", is_stack_sorted(*set_list));
	return (is_stack_sorted(*set_list));
}

static int	head_3(int next, int count, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if ((*set_list)->rank < next && next < mid)
	{
		rra(set_list);
		return (rra(set_list), 0);
	}
	if (count == 4 && next == 4)
	{
		ra(set_list);
		ra(set_list);
	}
	else if (prev == count)
		sa(set_list);
	else
		rra(set_list);
	return (is_stack_sorted(*set_list));
}

// cbdea -> sa bcdea -> rd abcde
// cadeb -> sa acdeb -> rd bacde ->sa abcde
// cdaeb -> ru x 2 aebcd -> sa eabcd ->ru abcde 
// cbaed -> rd x 2 edcba -> sa decba -> ru x 2 cbade -> sa bcade -> ru cadeb -> sa acdeb -> rd bacde -> sa abcde

static int	head_4(int next, int last, int count, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if (next < mid && mid < prev)
		return (rra(set_list), 0);
	if (last == count)
		return (rra(set_list), 0);
	if (last == 3)
		ra(set_list);
	else if (prev == 3)
		rra(set_list);
	else
		sa(set_list);
	return (is_stack_sorted(*set_list));
}

int	sort_ops_a(t_struct *structure, int set_size)
{
	int	next;
	// int	prev;
	int	last;
	int	head;

	if (is_stack_sorted(structure->head_a))
		return (1);
	update_rank(structure->head_a, set_size);
	head = structure->head_a->rank;
	next = structure->head_a->next->rank;
	// prev = structure->head_a->prev_to_last->rank;
	last = structure->head_a->last->rank;
	if (head == 1)
		return (head_1(next, last, set_size, &structure->head_a));
	if (head == 2)
		return (head_2(next, last, set_size, &structure->head_a));
	if (head == 3)
		return (head_3(next, set_size, &structure->head_a));
	if (head == 4)
		return (head_4(next, last, set_size, &structure->head_a));
	// if (head == 5)
	//     return (head_5(structure, set_size))
	return (0);
}
