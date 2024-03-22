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

int	tiny_sort(t_struct *structure)
{
	int	first;
	int	mid;
	int	last;
	int	size;

	size = count_nodes(structure->head_a);
	if (size == 2)
		return (swap_stack(structure, 'a'), 1);
	first = structure->head_a->value;
	mid = structure->head_a->next->value;
	last = structure->head_a->next->next->value;
	if (first > mid)
	{
		if (first > last && mid < last)
			rotate_up_stack(structure, 'a');
		else
			swap_stack(structure, 'a');
	}
	else
		rotate_down_stack(structure, 'a');
	return (is_stack_sorted(structure->head_a));
}

int	is_column_complete(t_node *list, int bit, int i)
{
	t_node	*cur;
	int		bit_cur;

	cur = list;
	while (cur != NULL)
	{
		bit_cur = cur->bit[i];
		if (bit_cur == bit)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
}

int	select_bit(t_node *list, int bit_count, int i)
{
	int		zeros;
	int		ones;
	int		bit_cur;
	t_node	*cur;

	zeros = 0;
	ones = 0;
	cur = list;
	while (cur != NULL)
	{
		bit_cur = cur->rank;
		if (bit_cur & (1 << (bit_count - i)))
			ones++;
		else
			zeros++;
		cur = cur->next;
	}
	if (max_value(zeros, ones) == 1)
		return (1);
	return (0);
}

