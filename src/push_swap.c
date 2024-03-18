/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/18 18:35:55 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_ab(t_struct *structure, int count_b)
{
	int	err;
	int	head_group;

	while (count_b > 0)
	{
		count_b = count_nodes(structure->head_b);
		rank_elems(structure->head_b);
		head_group = find_group(count_b, structure->head_a->rank);
		err = 0;
		if (head_group > 2)
		{
			pa(&structure->head_a, &structure->head_b, &err);
			if (err)
				err_handling(structure);
			if (structure->head_a->next != NULL
				&& structure->head_a->value > structure->head_a->next->value)
				ra(&structure->head_a);
		}
		else
			rrb(&structure->head_b);
	}
}

int	rotate_direction(int size, int big, int small)
{
	int	mid;
	int	rot_dir;

	mid = size / 2;
	rot_dir = -1;
	if (big <= mid)
	{
		if (small < mid || big < (size - small))
			rot_dir = 1; //ra
		else if (big > (size - small))
			rot_dir = 2; //rra
	}
	else if (big > mid)
	{
		if (small >= mid || small > (size - big))
			rot_dir = 2; //rra
		else if (small < (size - big))
			rot_dir = 1; //ra
	}
	return (rot_dir);
}

void	call_b(t_struct *structure, int count)
{
	int	small;
	int	sec_small;
	int	head_group;
	int	pos1;
	int	pos2;

	count = count_nodes(structure->head_a);
	rank_elems(structure->head_a);
	small = find_smallest(structure->head_a, count);
	pos1 = find_position(structure->head_a, small);
	sec_small = find_sec_smallest(structure->head_a, count, small);
	pos2 = find_position(structure->head_a, sec_small);
	head_group = find_group(count, structure->head_a->rank);
	if (count <= 4)
		sort_in_a(structure, count);
	else
	{
		if (head_group <= 2)
			push_sort_b(structure, head_group);
		else if (rotate_direction(count, pos2, pos1) == 1)
			ra(&structure->head_a);
		else if (rotate_direction(count, pos2, pos1) == 2)
			rra(&structure->head_a);
		call_b(structure, count);
	}
	merge_ab(structure, count_nodes(structure->head_b));
}

void	push_swap(t_struct *structure, int size)
{
	if (structure->head_a && is_stack_sorted(structure->head_a))
	{
		// printf("Already sorted!\n");
		return ;
	}
	if (size <= 5)
		sort_in_a(structure, size);
	// if (is_stack_sorted(structure->head_a))
		// printf("stack_a is sorted!\n");
	else
	{
		// printf("need stack_b\n");
		//while (!is_stack_sorted(structure->head_a))
		call_b(structure, size);
	}
	if (is_stack_sorted(structure->head_a)
		&& (count_nodes(structure->head_a) == structure->count))
		printf("stack_a is sorted!\n");
}

int	main(int argc, char **argv)
{
	t_struct	*structure;
	int			elements_count;
	char		**list;

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
	t_node *printme = structure->head_a;
	while (printme != NULL)
	{
		printf("%i\n", printme->value);
		printme = printme->next;
	}
	return (free_struct(structure), 0);
}
//for i in {-100..200}; do echo $i; done | sort -R | tr '\n' ' '
