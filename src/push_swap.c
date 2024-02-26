/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/02/26 16:32:57 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	is_set_sorted(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] > array[i + 1])
			return (0);
		//printf("test sort index: %i\n", array[i]);
		i++;
	}
	return (1);
}

void	tiny_sort_a(t_struct *structure)
{
	int	size;

	//printf("test list size: %i\n", structure->count);
	size = structure->count;
	if (size == 2)
		return (sa(&structure->head_a));
	if (size == 3)
	{
		rra(&structure->head_a);
		if (!is_stack_sorted(structure->head_a))
			return (sa(&structure->head_a));
	}
}

void	push_swap(t_struct *structure, int size)
{
	int	next_size;
	
	if (structure->head_a && is_stack_sorted(structure->head_a))
	{
		printf("Already sorted!\n");
		return ;
	}
	if (structure->count <= 3)
		tiny_sort_a(structure);
	// next_size = size / 5;
	// else if (next_size > 0)
	while (size / 5 > 0)
	{
		// printf("WORK IN PROGRESS...\n");
		// push_swap(structure, size / 5);
		// size = size / 5;
		call_b(structure, size);
		return ;
	}
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
	if (!list)
		return (0);
	if (check_errors(elements_count, list))
		return (write (2, "Error\n", 6));
	structure = struct_init(list, elements_count);
	if (!structure)
		return (err_handling(structure), 0);
	if (argc == 2)
		free_tab(list);
	push_swap(structure, structure->count);
	return (free_struct(structure), 0);
}
