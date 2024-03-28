/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/28 17:00:50 by skanna           ###   ########.fr       */
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
		// sec_smallest = sec_smallest(structure->head_a, count, smallest);
		position = find_position(structure->head_a, smallest);
		// sec_smallest = find_position(sec_smallest);
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
	if (count_nodes(structure->head_a) <= 3 && !is_stack_sorted(structure->head_a))
		tiny_sort(structure, count_nodes(structure->head_a));
	while (structure->head_b != NULL)
		push_to_stack(structure, 'a');
	return ;
}

int	do_rotations(t_struct *structure, int rotations, int to_move)
{
	if (!to_move && rotations == count_nodes(structure->head_a))
		return (0);
	if (!to_move && rotations == (count_nodes(structure->head_a) - 1))
	{
		rotate_down_stack(structure, 'a');
		return (0);
	}
	else
		rotate_up_stack(structure, 'a');
	return (1);
}

void	radix_sort(t_struct *structure, int start)
{
	int	cur_bit;
	int	rotations;
	int	move_to_b;

	move_to_b = count_bits(structure->head_a, 0, start);
	rotations = count_nodes(structure->head_a) - move_to_b;
	if (structure->count <= 7)
		return (sort_7(structure, structure->count));
	while (move_to_b >= 0 && rotations > 0)
	{
		cur_bit = (structure->head_a->rank >> start) & 1;
		if (cur_bit == 0)
		{
			push_to_stack(structure, 'b');
			move_to_b--;
		}
		else
		{
			if (!do_rotations(structure, rotations, move_to_b))
				break ;
			rotations--;
		}
	}
	sort_b(structure, ++start);
	if (structure->head_b != NULL)
		radix_sort(structure, start);
}

	// printf("\n--- stack A2 ---\n");
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("a: %i\n", printme->rank);
	// printf("\n--- stack B2 ---\n");
	// for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
	// 	printf("B: %i\n", printme->rank);

void	push_swap(t_struct *structure, int size)
{
	if (structure->head_a && is_stack_sorted(structure->head_a))
		return ;
	if (size <= 3)
		tiny_sort(structure, size);
	else
	{
		radix_sort(structure, 0);
	}
	// if (is_stack_sorted(structure->head_a)
	// 	&& (count_nodes(structure->head_a) == structure->count))
	// 	printf("stack_a is sorted!\n");
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
