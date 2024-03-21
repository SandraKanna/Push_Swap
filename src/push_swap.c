/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/19 19:01:29 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_direction(int size, int pos1, int pos2)
{
	int	mid;
	int	rot_dir;

	mid = size / 2;
	rot_dir = -1;
	if (pos1 <= mid)
	{
		if (pos2 < mid || pos1 < (size - pos2))
			rot_dir = 1; //ra
		else if (pos1 > (size - pos2))
			rot_dir = 2; //rra
	}
	else if (pos1 > mid)
	{
		if (pos2 >= mid || pos2 > (size - pos1))
			rot_dir = 2; //rra
		else if (pos2 < (size - pos1))
			rot_dir = 1; //ra
	}
	return (rot_dir);
}

void	push_swap(t_struct *structure, int size)
{
	if (structure->head_a && is_stack_sorted(structure->head_a))
		return ;
	if (size <= 3)
	{
		while(!is_stack_sorted(structure->head_a))
			tiny_sort(structure);
	}
	else
	{
		raidx_sort(structure, size);
	}
	if (is_stack_sorted(structure->head_a)
		&& (count_nodes(structure->head_a) == structure->count))
		printf("stack_a is sorted!\n");
}

int	main(int argc, char **argv)
{
	t_struct		*structure;
	int	elements_count;
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
	//push_swap(structure, structure->count);
	// t_node *printme = structure->head_a;
	// while (printme != NULL)
	// {
	// 	printf("%i\n", printme->value);
	// 	printme = printme->next;
	// }
	return (free_struct(structure), 0);
}

//for i in {-10..20}; do echo $i; done | sort -R | tr '\n' ' '
