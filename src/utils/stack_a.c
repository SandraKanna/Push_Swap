/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                            :+:      :+:    :+: */
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
	if (next == 2 || next == 3)
	{
		if (next == 2 && ((prev == 3 && last == 5) || (prev == 4 && last == 5)))
			ra(set_list);
		else if (next == 3 && (last == count && mid != 4))
			ra(set_list);
		else
			rra(set_list);
	}
	else if (next == 4 || next == 5)
	{
		if (next == 4 && last == 2)
			ra(set_list);
		else
			sa(set_list);
	}
	return (is_stack_sorted(*set_list));
}

static int	head_2(int next, int last, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if (next == 1 || next == 5)
	{
		if (next == 5 && mid == 4)
			ra(set_list);
		else
			sa(set_list);
	}
	else if (next == 3 || next == 4)
	{
		if ((next == 4 && mid == 1) || (next == 3 && ((mid == 1 && prev != 5)
					|| (last == 1 && prev != 5))))
			ra(set_list);
		else if (next == 4 && mid == 1 && prev != 5)
			sa(set_list);
		else
			rra(set_list);
	}
	return (is_stack_sorted(*set_list));
}

static int	head_3(int next, int last, t_node **set_list)
{
	int	mid;

	mid = find_mid_of_set(*set_list)->rank;
	if (next == 1 || next == 2)
	{
		if (next == 1 && mid == 5)
			rra(set_list);
		else
			sa(set_list);
	}
	else if (next == 4 || next == 5)
	{
		if (next == 4 && (last == 5 || mid == 5))
			rra(set_list);
		else if (next == 5 && last == 4)
			sa(set_list);
		else
			ra(set_list);
	}
	return (is_stack_sorted(*set_list));
}

static int	head_4(int next, int last, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
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
		if (next == 2 && mid == 1 && last == 5)
			rra(set_list);
		else
			sa(set_list);
	}
	return (is_stack_sorted(*set_list));
}

static int	head_5(int next, int last, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if (next == 1 || next == 2)
	{
		if ((last == 4 && prev == 3) || (mid == 3 && last == 4)
			|| (mid == 2 && prev == 3))
			ra(set_list);
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
		return (head_2(next, last, &structure->head_a));
	if (head == 3)
		return (head_3(next, last, &structure->head_a));
	if (head == 4)
		return (head_4(next, last, &structure->head_a));
	if (head == 5)
	    return (head_5(next, last, &structure->head_a));
	return (0);
}


/*
old one:

static int	head_1(int next, int last, int count, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if (next < mid)
	{
		if (count == 4 || (next != 4 && (mid == 5 || prev == 5)))
		// if (next < mid && mid < 4)
			rra(set_list);
	}
	else if ((count == 4 && prev == 2) || (count == 5 && mid == 2))
	// else if (next !=  2 && mid != 3)
		sa(set_list);
	else if (count == 4 && (next == 2 || last == count || prev == count - 1))
		ra(set_list);
	return (is_stack_sorted(*set_list));
}

static int	head_2(int next, int last, int count, t_node **set_list)
{
	int	mid;
	int	prev;


	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	// printf ("test head 2 prev: %i\n", prev);
	if (next != 3)
		sa(set_list);
	else if (next == 3 && prev > last)
		rra(set_list);
	else if ((*set_list)->rank < next)
	{
		if ((count == 5 && next < mid) || (count == 4
				&& next < prev))
			rra(set_list);
	}
	// else if (mid == 1 || (last == 1 && next == 3))
	// 	rra(set_list);
	else if ((count == 4 && next < prev)
		|| (next < mid && mid < prev))
		ra(set_list);

	// printf ("is sorted: %i\n", is_stack_sorted(*set_list));
	return (is_stack_sorted(*set_list));
}

static int	head_3(int next, int count, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if (count != 5 && ((*set_list)->rank < next && next < mid))
		rra(set_list);
	else if (next == 4)
	{
		if (mid == 5)
			rra(set_list);
		else
			ra(set_list);
	}
	else if (prev == count)
		sa(set_list);
	else
		rra(set_list);
	return (is_stack_sorted(*set_list));
}

static int	head_4(int next, int last, int count, t_node **set_list)
{
	// int	mid;
	int	prev;

	// mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	// if (next < mid && mid < prev)
	// 	rra(set_list);
	if (last == count || prev == 3)
		rra(set_list);
	else if (last == 3 || next == 5)
		ra(set_list);
	// else if (prev == 3)
	// 	rra(set_list);
	else
		sa(set_list);
	return (is_stack_sorted(*set_list));
}

static int	head_5(int next, int last, t_node **set_list)
{
	int	mid;
	int	prev;

	mid = find_mid_of_set(*set_list)->rank;
	prev = find_prev_to_last(*set_list)->rank;
	if (next == 4)
		sa(set_list);
	else if (last == 4 || mid == 4)
		ra(set_list);
	else if (next < mid && mid < prev)
		rra(set_list);
	return (is_stack_sorted(*set_list));
}

*/