/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/04/17 00:30:47 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_struct *structure, int size)
{
	int	initial_groups;

	initial_groups = structure->len_bits - 1;
	if (structure->a && is_stack_sorted(structure->a, size))
		return ;
	if (size <= 3)
		base_case(structure, size);
	else
	{
		divide_list(structure, size, initial_groups);
		sort_list(structure);
	}
	// if (is_stack_sorted(structure->a, size)
	// 	&& (count_nodes(structure->a) == structure->count))
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
	list = check_input(&elements_count, argc, argv);
	if (!list)
		return (0);
	structure = init_struct(list, elements_count);
	if (argc == 2)
		free_tab(list);
	if (!structure)
		return (0);
	push_swap(structure, structure->count);
	// printf("\n--- final stack A ---\n");
	// for (t_node *printme = structure->a; printme != NULL; printme = printme->next)
	// 	printf("A: %i\n", printme->rank);
	return (free_struct(structure), 0);
}

//for i in {0..101}; do echo $i; done | sort -R | tr '\n' ' '