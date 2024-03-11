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

	mid = find_mid_of_set(*set_list)->rank;
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
		if (mid == 4 || ((mid == 3 && last == 5) || (mid == 5 && prev == 3)
			|| (mid == 2 && prev == 5)))
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

	mid = find_mid_of_set(*set_list)->rank;
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

	mid = find_mid_of_set(*set_list)->rank;
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

int	head_4(int next, int last, t_node **set_list)
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
		if (next == 3 && mid == 2 && last == 5)
			return (5);
		if (next == 2 && mid == 1 && last == 5)
			rra(set_list);
		else
			sa(set_list);
	}
	return (is_stack_sorted(*set_list));
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
