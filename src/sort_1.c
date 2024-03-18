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

//#include "../Includes/push_swap.h"
#include "push_swap.h"

void	push_sort_b(t_struct *structure, int head_b_group)
{
	int		err;
	t_node	*top_b;
	int		head_a_group;
	//int		head_a_next_group;

	err = 0;
	pb(&structure->head_a, &structure->head_b, &err);
	if (err)
		err_handling(structure);
	top_b = structure->head_b;
	head_a_group = find_group(count_nodes(structure->head_a), structure->head_a->rank);
	//head_a_next_group = find_group(count_nodes(structure->head_a), structure->head_a->next->rank);
	if (top_b->next != NULL)
	{
		if (head_b_group == 1)
		{
			if (head_a_group > 2)
				rr(&structure->head_a, &structure->head_b);
			else
				rb(&structure->head_b);
		}
		// else
		// {
		// 	if (top_b->value > top_b->next->value)
		// 	{
		// 		if (head_a_next_group <= 2)
		// 			ss(&structure->head_a, &structure->head_b);
		// 		else
		// 			sb(&structure->head_b);
		// 	}
		// }
	}
	t_node *temp = structure->head_b;
	int i = 0;
	while (temp != NULL && i < 100)
	{
		printf("b[%i]: %i\n", i, temp->value);
		i++;
		temp = temp->next;
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

int	sort_in_a(t_struct *structure, int size)
{
	int	i;

	i = size + 2;
	if (size <= 3)
	{
		while (i > 0)
		{
			if (tiny_sort(structure))
				return (is_stack_sorted(structure->head_a));
			i--;
		}
	}
	while (i > 0)
	{
		if (sort_5(structure))
			break ;
		i--;
	}
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
