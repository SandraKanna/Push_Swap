/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/04/15 17:15:31 by skanna           ###   ########.fr       */
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
		base_case_1(structure, count_nodes(structure->head_a));
	while (structure->head_b != NULL)
		push_to_stack(structure, 'a');
	return ;
}

void	divide_list(t_struct *structure, int size, int groups)
{
	int	elems_in_group;
	int	remainder_a;
	int	i;

	elems_in_group = size / groups;
	i = 1;
	while (i < groups)
	{
		remainder_a = create_group(structure, elems_in_group, i);
		printf("\n--- test divide 1 ---\n");
		i++;
	}
	if (remainder_a > 6 && i < groups)
	{
		printf("\n--- test divide 2 ---\n");
		divide_list(structure, remainder_a, groups / 2);
	}
	else
		return (last_division(structure, remainder_a));
}

void	sort_list(t_struct *structure)
{
	int	biggest;

	// biggest = structure->head_a->rank - 1;
	while (structure->head_b != NULL)
	{
		biggest = structure->head_a->rank - 1;
		if (structure->head_b->rank == biggest)
			push_to_stack(structure, 'a');
		else if (structure->head_b->next->rank == biggest)
		{
			if (structure->head_a->rank > structure->head_a->next->rank)
				swap_stack(structure, 'c');
			else
				swap_stack(structure, 'b');
		}
		else
			best_rotation(structure, biggest, 'b');
	}
}

void	push_swap(t_struct *structure, int size)
{
	int	initial_groups;

	initial_groups = structure->len_bits - 1;
	printf("\n--- initial groups : %i ---\n", initial_groups);
	if (structure->head_a && is_stack_sorted(structure->head_a, size))
		return ;
	if (size <= 3)
		base_case_1(structure, size);
	else
	{
		divide_list(structure, size, initial_groups);
		sort_list(structure);
	}
	// if (is_stack_sorted(structure->head_a, size)
	// 	&& (count_nodes(structure->head_a) == structure->count))
	// 	printf("n: %i stack_a is sorted!\n", size);
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
	// printf("\n--- initial stack A ---\n");
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("A: %i\n", printme->rank);
	push_swap(structure, structure->count);
	return (free_struct(structure), 0);
}

//for i in {0..101}; do echo $i; done | sort -R | tr '\n' ' '
