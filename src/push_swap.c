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
			break;
	}
	if (count_nodes(structure->head_a) <= 3 && !is_stack_sorted(structure->head_a, count))
		tiny_sort(structure, count_nodes(structure->head_a));
	while (structure->head_b != NULL)
		push_to_stack(structure, 'a');
	return ;
}

int	do_rotations(t_struct *structure, char c, int rot, int to_move)
{
	t_node	*last;

	last = find_last(structure->head_a);
	if (c == 'a')
	{
		// if (!to_move && rot == count_nodes(structure->head_a))
		// 	return (0);
		// if (!to_move && rot == (count_nodes(structure->head_a) - 1))
		// 	rotate_down_stack(structure, c);
		// else
		// 	return (rotate_up_stack(structure, c), 1);
		if (!to_move && rot == 0)
			return (0);
		if (to_move && (last->rank < structure->head_a->rank))
			rotate_down_stack(structure, c);
		else
			return (rotate_up_stack(structure, c), 1);
	}
	else if (c == 'b')
	{
		last = find_last(structure->head_b);
		if (!to_move && rot == 0)
			return (0);
		if (to_move && (last->rank > structure->head_b->rank))
			rotate_down_stack(structure, c);
		else
			return (rotate_up_stack(structure, c), 1);
	}
	return (-1);
}


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

	// printf("\n--- stack A2 ---\n");
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("a: %i\n", printme->rank);
	// printf("\n--- stack B2 ---\n");
	// for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
	// 	printf("B: %i\n", printme->rank);

void	radix_sort(t_struct *structure, int start, int end, int to_sort)
{
	int	count_a;

	count_a = count_nodes(structure->head_a);
	if (count_a <= 3 && !is_stack_sorted(structure->head_a, 3))
		tiny_sort(structure, count_a);
	// to_sort = count_nodes(structure->head_b);
	if (to_sort > 0 && start <= end)
	{
		if (to_sort == 1)
			sort_b(structure, start++, to_sort * 2);
		if (to_sort != 1 && to_sort / 2 >= 1)
		{
			to_sort /= 2;
			radix_sort(structure, start, end, to_sort);
		}
		// sort_b(structure, start++, to_sort * 2);
	}
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

void	divide_and_conquer(t_struct *structure, int size, int iterations)
{
	int	send_to_b;
	int	biggest;
	int	i;
	int	mid;

	i = iterations;
	while (i > 0 && size > 3)
	{
		biggest = find_biggest(structure->head_a, size);
		send_to_b = size / 2;
		mid = get_mid(structure->head_a, size);
		if (size % 2 != 0)
			send_to_b += 1;
		while (send_to_b > 0 && size > 3)
		{
			if (structure->head_a->rank <= mid
				&& structure->head_a->rank < (biggest - 2))
			{
				push_to_stack(structure, 'b');
				send_to_b--;
			}
			else
				rotate_up_stack(structure, 'a');
			size = count_nodes(structure->head_a);
		}
		i--;
	}
}

void	push_swap(t_struct *structure, int size)
{
	int	iterations;

	iterations = structure->len_bits - 1;
	if (structure->head_a && is_stack_sorted(structure->head_a, size))
		return ;
	if (size <= 3)
		return (tiny_sort(structure, size));
	divide_and_conquer(structure, size, iterations);
	radix_sort(structure, 0, iterations, count_nodes(structure->head_b));
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
	// printf("\n--- final stack A ---\n");
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("A: %i\n", printme->rank);
	return (free_struct(structure), 0);
}

//for i in {0..101}; do echo $i; done | sort -R | tr '\n' ' '
