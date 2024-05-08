/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/04/17 14:06:32 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_struct *structure, int size)
{
	int	initial_groups;

	initial_groups = structure->len_bits - 1;
	if (structure->a && is_stack_sorted(structure->a, size))
		return ;
	if (size <= 7)
		base_case_2(structure, size);
	else
	{
		divide_list(structure, size, initial_groups);
		sort_list(structure);
	}
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
	return (free_struct(structure), 0);
}
