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

int	count_bits(t_node *list, int bit, int i)
{
	t_node	*cur;
	int		bit_cur;
	int		count;

	cur = list;
	count = 0;
	while (cur != NULL)
	{
		bit_cur = (cur->rank >> i) & 1;
		if (bit_cur == bit)
			count++;
		cur = cur->next;
	}
	return (count);
}

int	is_column_complete(t_node *list, int bit, int i)
{
	t_node	*cur;
	int		bit_cur;

	cur = list;
	while (cur != NULL)
	{
		bit_cur = (cur->rank >> i) & 1;
		if (bit_cur == bit)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
}

void	sort_b(t_struct *structure, int bit_column, int end)
{
	int		holder1;
	int		move_to_a;

	printf("\n--- stack B ---\n");
	for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
		printf("B: %i\n", printme->rank);
	move_to_a = count_bits(structure->head_b, 1, bit_column);
	if (bit_column == end)
	{
		while (structure->head_b != NULL)
		{
			// rotate_down_stack(structure, 'b');
			push_to_stack(structure, 'a');
		}
	}
	while (structure->head_b != NULL && move_to_a > 0)
	{
		holder1 = (structure->head_b->rank >> bit_column) & 1;
		printf ("rank: %i, next bit: %i\n", structure->head_b->rank, holder1);
		if (holder1 == 1)
		{
			push_to_stack(structure, 'a');
			// rotate_up_stack(structure, 'a');
			move_to_a--;
		}
		else
		{
			rotate_up_stack(structure, 'b');
		}
	}

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

