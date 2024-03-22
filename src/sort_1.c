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

void	sort_column(t_struct *structure, int count_a, int i, int bit)
{
	int		cur_bit;
	t_node	*a;

	a = structure->head_a;
	while (count_a > 0)
	{
		if (is_column_complete(a, bit, i))
			break ;
		cur_bit = a->bit[i];
		printf("Current bit: %d   target bit: %d\n", a->bit[i], bit);
		if (cur_bit != bit)
		{
			push_to_stack(structure, 'b');
			rotate_up_stack(structure, 'b');
		}
		else
			push_to_stack(structure, 'b');
		a = structure->head_a;
		count_a = count_nodes(a);
	}
	t_node *printme = structure->head_a;
	while (printme != NULL)
	{
		printf("A: %i\n", printme->value);
		printme = printme->next;
	}
	printme = structure->head_b;
	while (printme!= NULL)
	{
		printf("stack_B: %i\n", printme->value);
		printme = printme->next;
	}
	bit = select_bit(structure->head_b, structure->len_bits, i);
	printf ("bit_b: %i\n", bit);
	sort_column_b(structure, i++, bit);
}

void	sort_column_b(t_struct *structure, int i, int bit)
{
	t_node	*b;

	b = structure->head_b;
	if (b == NULL)
		return ;
	while (b != NULL)
	{
		// if (is_column_complete(b, bit, i))
		// 	break ;
		printf("Current bit_b: %d   target bit: %d\n", b->bit[i], bit);
		if (b->bit[i] != bit)
		{
			// if (i < structure->len_bits && b->bit[i + 1] == 1)
			// if (b->next != NULL && b->rank < b->next->rank)
			// 	swap_stack(structure, 'b');
			push_to_stack(structure, 'a');
		}
		else
		{
			push_to_stack(structure, 'a');
			rotate_up_stack(structure, 'a');
		}
		b = structure->head_b;
	}
}

