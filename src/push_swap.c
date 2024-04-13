/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/04/13 13:57:24 by skanna           ###   ########.fr       */
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

void	divide_and_conquer(t_struct *structure, int size, int total_groups)
{
	int	elems_in_group;
	int	send_to_b;
	int	mid;
	int	max;

	elems_in_group = size;
	send_to_b = elems_in_group;
	max = size - elems_in_group;
	mid = (size - max) / 2;;
	printf("\nmax iter: %i ---\n", total_groups);
	if (size > 4)
	{
		elems_in_group = size / total_groups;
		while (elems_in_group > 0)
		{
			if (structure->head_a->rank < elems_in_group)
		}
		
	}
	divide_and_conquer(structure, size, total_groups / 2);
}

void	push_swap(t_struct *structure, int size)
{
	int	total_groups;

	//iterations = structure->len_bits - 1;
	total_groups = structure->len_bits;
	// printf("\n--- len bits: %i ---\n", structure->len_bits);
	if (structure->head_a && is_stack_sorted(structure->head_a, size))
		return ;
	if (size <= 3)
		tiny_sort(structure, size);
	else
	{
		divide_and_conquer(structure, size, total_groups);
		// printf("\n--- total_groups : %i ---\n", total_groups);
		radix_sort(structure, total_groups);
	}
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
