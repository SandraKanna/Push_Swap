/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/04/05 19:20:18 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_7(t_struct *structure, int count)
{
	int	smallest;
	int	position;
	int	move_to_b;

	move_to_b = count - 3;
	while (structure->head_a != NULL)
	{
		smallest = find_smallest(structure->head_a, count);
		position = find_position(structure->head_a, smallest);
		if (move_to_b > 0)
		{
			if (structure->head_a->rank == smallest)
			{
				push_to_stack(structure, 'b');
				move_to_b--;
			}
			else if (position <= count / 2)
				rotate_up_stack(structure, 'a');
			else
				rotate_down_stack(structure, 'a');
		}
		if (count_nodes(structure->head_a) == 3)
			break ;
	}
	if (count_nodes(structure->head_a) <= 3
		&& !is_stack_sorted(structure->head_a, count))
		tiny_sort(structure, count_nodes(structure->head_a));
	while (structure->head_b != NULL)
		push_to_stack(structure, 'a');
	return ;
}

// void	radix_sort(t_struct *structure, int start, int end, int to_sort)
void	radix_sort(t_struct *structure, int batch)
{
	int	count_a;

	count_a = count_nodes(structure->head_a);
	if (batch == 0)
		return ;
	if (count_a <= 3 && !is_stack_sorted(structure->head_a, 3))
		tiny_sort(structure, count_a);

	batch -= 1;
	sort_batch(structure, 0, batch);
	if (structure->head_b != NULL)
		radix_sort(structure, batch);
}

int	get_mid(t_node *lst, int size)
{
	int	mid;
	int	smallest;
	int	biggest;

	smallest = find_smallest(lst, size);
	biggest = find_biggest(lst, size);
	mid = (smallest + biggest) / 2;
	return (mid);
}

int	divide_and_conquer(t_struct *structure, int size, int max_batches)
{
	int	to_move;
	int	moved;
	int	biggest;
	int	i;
	int	mid;

	i = 0;
	// printf("\nmax iter: %i ---\n", max_batches);
	while (i < max_batches && size > 3)
	{
		biggest = find_biggest(structure->head_a, size);
		to_move = size / 2;
		moved = 0;
		mid = get_mid(structure->head_a, size);
		if (size % 2 != 0)
			to_move += 1;
		while (moved < to_move && size > 3)
		{
			if (structure->head_a->rank <= mid
				&& structure->head_a->rank < (biggest - 2))
			{
				push_to_stack(structure, 'b');
				moved++;
			}
			else
				rotate_up_stack(structure, 'a');
			size = count_nodes(structure->head_a);
		}
		init_group_size(structure, i, max_batches, moved);
		i++;
	}
	// printf("\nactual batches: %i ---\n", i);
	return (i);
}

void	push_swap(t_struct *structure, int size)
{
	int	batches;

	//iterations = structure->len_bits - 1;
	printf("\n--- len bits: %i ---\n", structure->len_bits);
	if (structure->head_a && is_stack_sorted(structure->head_a, size))
		return ;
	if (size <= 3)
		return (tiny_sort(structure, size));
	batches = divide_and_conquer(structure, size, structure->len_bits - 1);
	printf("\n--- batches : %i ---\n", batches);
	printf("\n--- initial A ---\n");
	for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
		printf("A: %i\n", printme->rank);
	printf("\n--- initial B ---\n");
	for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
		printf("B: %i\n", printme->rank);
	radix_sort(structure, batches);
	if (is_stack_sorted(structure->head_a, size)
		&& (count_nodes(structure->head_a) == structure->count))
		printf("stack_a is sorted!\n");
}

int	main(int argc, char **argv)
{
	t_struct		*structure;
	int				elements_count;
	char			**list;

	if (argc < 2)
		return (0);
	elements_count = 0;
	list = parse_args(&elements_count, argc, argv);
	if (!list || !*list || check_errors(elements_count, list))
	{
		if (argc == 2 && list)
			free_tab(list);
		return (write (2, "Error\n", 6));
	}
	structure = init_struct(list, elements_count);
	if (argc == 2)
		free_tab(list);
	if (!structure)
		return (0);
	push_swap(structure, structure->count);
	printf("\n--- final stack A ---\n");
	for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
		printf("A: %i\n", printme->rank);
	return (free_struct(structure), 0);
}

//for i in {0..101}; do echo $i; done | sort -R | tr '\n' ' '




// int	do_rotations_a(t_struct *structure, int rot, int to_move)
// {
// 	t_node	*last;
// 	int		cur_bit;

// 	last = find_last(structure->head_a);
// 	if (!to_move && rot == count_nodes(structure->head_a))
// 		return (0);
// 	if (!to_move && rot == (count_nodes(structure->head_a) - 1))
// 		rotate_down_stack(structure, 'a');
// 	else
// 		return (rotate_up_stack(structure, 'a'), 1);
// 		// if (!to_move && rot == 0)
// 		// 	return (0);
// 		// if (to_move && (last->rank < structure->head_a->rank))
// 		// 	rotate_down_stack(structure, c);
// 		// else
// 		// 	return (rotate_up_stack(structure, c), 1);
// }

// void	radix_sort(t_struct *structure, int start)
// {
// 	int	cur_bit;
// 	int	rotations;
// 	int	move_to_b;

// 	move_to_b = count_bits(structure->head_a, 0, start);
// 	rotations = count_nodes(structure->head_a) - move_to_b;
// 	if (structure->count <= 7)
// 		return (sort_7(structure, structure->count));
// 	while (move_to_b >= 0 && rotations > 0)
// 	{
// 		cur_bit = (structure->head_a->rank >> start) & 1;
// 		if (cur_bit == 0)
// 		{
// 			push_to_stack(structure, 'b');
// 			move_to_b--;
// 		}
// 		else
// 		{
// 			if (!do_rotations(structure, rotations, move_to_b))
// 				break ;
// 			rotations--;
// 		}
// 	}
// 	sort_b(structure, ++start);
// 	if (structure->head_b != NULL)
// 		radix_sort(structure, start);
// }
