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

void	last_iteration(t_struct *structure, int bit_column)
{
	int	holder;
	int	smallest_b;
	int	group0;
	int	count_b;

	count_b = count_nodes(structure->head_b);
	group0 = count_bits(structure->head_b, 0, bit_column, count_b);
	printf("\n--- last iter : %i  count b: %i ---\n", bit_column, count_b);
	while (structure->head_b != NULL)
	{
		holder = (structure->head_b->rank >> bit_column) & 1;
		if (group0 > 0)
		{
			if (holder == 0)
			{
				push_to_stack(structure, 'a');
				group0--;
			}
			else
				rotate_up_stack(structure, 'b');
		}
		else
		{
			smallest_b = find_smallest_bit(structure->head_b, bit_column);
			if (structure->head_b->rank == smallest_b)
			{
				push_to_stack(structure, 'a');
				rotate_up_stack(structure, 'a');
			}
			else
				rotate_down_stack(structure, 'b');
		}
	}
}

void	sort_top(t_struct *structure, int to_sort)
{
	int		biggest_b;
	int		pos;
	int		i;
	int 	rot;

	i = 0;
	rot = 0;
	printf("\nsort top: %i ---\n", to_sort);
	// printf("\nstack B \n");
	// for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
	// 	printf("B: %i\n", printme->rank);
	while (i < to_sort)
	{
		biggest_b = find_biggest(structure->head_b, (to_sort - i - rot));
		pos = find_position(structure->head_b, biggest_b);
		if (to_sort <= 2)
		{
			if (structure->head_b->rank != biggest_b)
				swap_stack(structure, 'b');
			push_to_stack(structure, 'a');
			i++;
			
		}
		else if ((i == 0 && (structure->head_b->rank == biggest_b - 1)) || structure->head_b->rank == biggest_b)
		{
			push_to_stack(structure, 'a');
			if (structure->head_a->rank > structure->head_a->next->rank)
				swap_stack(structure, 'a');
			i++;
		}
		else if (rot < pos && rot + i < to_sort)
		{
			rotate_up_stack(structure, 'b');
			rot++;
		}
		else 
		{
			rotate_down_stack(structure, 'b');
			rot--;
		}
	}
	printf("\n Stack A\n");
	for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
		printf("A: %i\n", printme->rank);
// 	printf("\n----\n stack B \n");
// 	for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
// 		printf("B: %i\n", printme->rank);
}

int	sort_bit_a(t_struct *structure, int start, int work_set)
{
	int	to_move;
	int	moved;
	int	cur_bit;
	int	rot;

	moved = 0;
	rot = 0;
	printf("\n--- stack A before start: %i ---\n", start);
	for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
		printf("A: %i\n", printme->rank);
	to_move = count_bits(structure->head_a, 0, start, work_set);
	if (start == structure->len_bits - 1)
		return (0);
	while (moved < to_move && rot + moved < work_set)
	{
		cur_bit = (structure->head_a->rank >> start) & 1;
		// printf("\ncur_bit = %i \n", cur_bit);
		if (cur_bit == 0)
		{
			push_to_stack(structure, 'b');
			moved++;
		}
		else
		{
			rotate_up_stack(structure, 'a');
			rot += 1;
		}
	}
	if (rot > count_nodes(structure->head_a) - rot)
	{
		rot = count_nodes(structure->head_a) - rot;
		while (rot > 0)	
		{
			rotate_up_stack(structure, 'a');
			rot--;
		}
	}
	else
	{
		while (rot > 0)
		{
			rotate_down_stack(structure, 'a');
			--rot;
		}
	}
	printf("\nTest sort in a rot: %i kep in a: %i \n", rot, work_set - moved);
	printf("\n--- stack A after start: %i ---\n", start);
	for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
		printf("A: %i\n", printme->rank);
	return (work_set - moved);
}

int	sort_bit_b(t_struct *structure, int start, int group_size)
{
	int	to_move;
	int	moved;
	int	cur_bit;
	int	rot;

	moved = 0;
	rot = 0;
	to_move = count_bits(structure->head_b, 1, start, group_size);
	printf("\nB group size = %i   to move: %i \n", group_size, to_move);
	printf("\n--- stack B before start: %i ---\n", start);
	for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
		printf("B: %i\n", printme->rank);
	while (to_move > moved)
	{
		cur_bit = (structure->head_b->rank >> start) & 1;
		printf("\ncur_bit = %i \n", cur_bit);
		if (cur_bit == 1)
		{
			push_to_stack(structure, 'a');
			moved++;
		}
		else
		{
			rotate_up_stack(structure, 'b');
			rot += 1;
		}
	}
	if (rot > count_nodes(structure->head_b) - rot)
	{
		rot = count_nodes(structure->head_b) - rot;
		while (rot > 0)	
		{
			rotate_up_stack(structure, 'b');
			rot--;
		}
	}
	else
	{
		while (rot > 0)
		{
			rotate_down_stack(structure, 'b');
			--rot;
		}
	}
	printf("\n stack B after start: %i \n", start);
	for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
	printf("B: %i\n", printme->rank);
	return (moved);
}

void	sort_batch(t_struct *structure, int start, int batch)
{
	int		group_size;
	int		in_a;
	int		in_b;

	group_size = structure->group_size[batch];
	in_b = group_size;
	in_a = 0;
	printf("\n Batch: %i  elements: %i   start: %i \n", batch, group_size, start);
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("A: %i\n", printme->rank);
	// printf("\n----\n stack B \n");
	// for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
	// 	printf("B: %i\n", printme->rank);
	while (in_b > 0)
	{
		while (start < structure->len_bits)
		{
			// printf("\n--- start: %i ---\n", start);
			in_b = group_size - in_a;
			if (in_b <= 4 && is_stack_sorted(structure->head_a, in_a))
				return (sort_top(structure, in_b));
			if (start == structure->len_bits - 1)
			{
				while (structure->head_b != NULL)
					push_to_stack(structure, 'a');
				return ;
			}
			else
			{
				in_a += sort_bit_b(structure, start, in_b);
				in_a = sort_bit_a(structure, ++start, in_a);
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


