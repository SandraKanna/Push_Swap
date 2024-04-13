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

#include "push_swap.h"

void	tiny_sort(t_struct *structure, int size)
{
	int	smallest;
	int	biggest;

	// printf("\n--- test tiny ---\n");
	if (size == 2)
		return (swap_stack(structure, 'a'));
	smallest = find_smallest(structure->head_a, size);
	biggest = find_biggest(structure->head_a, size);
	if (smallest == structure->head_a->rank)
	{
		swap_stack(structure, 'a');
		rotate_up_stack(structure, 'a');
	}
	else if (smallest == structure->head_a->next->rank)
	{
		if (biggest == structure->head_a->rank)
			rotate_up_stack(structure, 'a');
		else
			swap_stack(structure, 'a');
	}
	else if (smallest == structure->head_a->next->next->rank)
	{
		if (biggest == structure->head_a->next->rank)
			rotate_down_stack(structure, 'a');
		else
		{
			swap_stack(structure, 'a');
			rotate_down_stack(structure, 'a');
		}
	}
}


void	sort_batch(t_struct *structure, int start, int batch)
{
	int		group_size;
	int		in_a;
	int		in_b;
	int		biggest;

	group_size = structure->group_size[batch];
	in_b = group_size;
	in_a = 0;
	// printf("\n Batch: %i  elements: %i   start: %i \n", batch, group_size, start);
	while (in_b > 0)
	{
		while (start <= structure->len_bits)
		{			
			// if (start == structure->len_bits)
			// {
			// 	// while (structure->head_b != NULL)
			// 	// 	push_to_stack(structure, 'a');
			// 	return ;
			// }
			in_b = group_size - in_a;
			biggest = find_biggest(structure->head_b, count_nodes(structure->head_b));
			printf("\n--- start: %i   len bits: %i  big: %i---\n", start, structure->len_bits, biggest);
			if (start == structure->len_bits - 1)
			 	return (sort_last_batch(structure, in_b, biggest));
			if (in_b <= 4 && is_stack_sorted(structure->head_a, in_a))
				return (sort_top(structure, in_b));
			in_a += sort_bit_b(structure, start, in_b, biggest);
			in_a = sort_bit_a(structure, ++start, in_a, biggest);
			if (find_position(structure->head_a, biggest) == in_a)
			{
				group_size -= 1;
				in_a -= 1;
			}
		}
	}

}

// void	sort_b(t_struct *structure, int start, int index)
// {
// 	int		cur_bit;
// 	int		move_to_a;
// 	int		remainder_a;
// 	int		i;
// 	int		rot;
// 	t_node	*b;

// 	rot = 0;
// 	remainder_a = 0;
// 	while (start < structure->len_bits)
// 	{
// 		i = 0;
// 		move_to_a = count_bits(structure->head_b, 1, start, structure->group_size[index]);
// 		printf("\nGroup size: %i : \n", structure->group_size[index]);
// 		printf("\nMove to a: %i, start: %i ---\n", move_to_a, start);
// 		if (structure->group_size[index] <= 3)
// 			return (sort_top_3(structure, move_to_a));
// 		while (i < move_to_a && structure->head_b != NULL)
// 		{
// 			b = structure->head_b;
// 			cur_bit = (b->rank >> start) & 1;
// 			if (cur_bit == 1)
// 			{
// 				push_to_stack(structure, 'a');
// 				i++;
// 			}
// 			else
// 			{
// 				rotate_up_stack(structure, 'b');
// 				rot += 1;
// 			}
// 		}
// 		while (rot > 0 && rot < count_nodes(structure->head_b))
// 		{
// 			rotate_down_stack(structure, 'b');
// 			rot--;
// 		}
// 		remainder_a += sort_a(structure, ++start, i + remainder_a, index);
// 		printf("\nremainder_a: %i \n", remainder_a);
// 	}
// }

// void	sort_b(t_struct *structure, int bit_column)
// {
// 	int		holder1;
// 	int		move_to_a;
// 	int		keep_in_b;

// 	if (is_stack_sorted(structure->head_a))
// 		return (last_iteration(structure, bit_column));
// 	holder1 = -1;
// 	move_to_a = count_bits(structure->head_b, 1, bit_column);
// 	keep_in_b = count_bits(structure->head_b, 0, bit_column);
// 	while (structure->head_b != NULL
// 		&& (move_to_a > 0 || (move_to_a == 0 && keep_in_b > 0)))
// 	{
// 		holder1 = (structure->head_b->rank >> bit_column) & 1;
// 		if (holder1 == 1)
// 		{
// 			push_to_stack(structure, 'a');
// 			move_to_a--;
// 		}
// 		else
// 		{
// 			rotate_up_stack(structure, 'b');
// 			keep_in_b--;
// 		}
// 	}

// }


// void	sort_last_batch(t_struct *structure, int in_b, int big)
// {
// 	// int	biggest;
// 	int	big_position;
// 	int	i;
// 	int rot;

// 	// biggest = find_biggest(structure->head_b, in_b);
// 	big_position = find_position(structure->head_b, big);
// 	i = big_position;
// 	rot = 0;
// 	printf("\n--- last batch biggest: %i  big position: %i---\n", big, big_position);
// 	printf("\n----\n stack B \n");
// 	for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
// 		printf("B: %i\n", printme->rank);
// 	if (big_position > count_nodes(structure->head_b) / 2)
// 	{
// 		i = count_nodes(structure->head_b) - big_position;
// 		while (i >= 0)
// 		{
// 			rotate_down_stack(structure, 'b');
// 			i--;
// 		}
// 	}
// 	else
// 	{
// 		while (i > 1)
// 		{
// 			rotate_up_stack(structure, 'b');
// 			i--;
// 			rot++;
// 		}
// 		push_to_stack(structure, 'a');
// 		in_b--;
// 	}
// 	while(rot > 0)
// 	{
// 		rotate_down_stack(structure, 'b');
// 		rot--;
// 	}
// 	while (in_b > 0)
// 	{
// 		push_to_stack(structure, 'a');
// 		in_b--;
// 	}
// 	// printf("\n----\n stack A \n");
// 	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
// 	// printf("A: %i\n", printme->rank);
// }