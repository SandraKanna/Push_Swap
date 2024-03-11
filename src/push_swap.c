/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/11 19:02:13 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	sort_in_a(t_struct *structure, int size)
{
	int	i;

	i = size + 3;
	if (size <= 3)
	{
		while (i > 0)
		{
			if (tiny_sort(structure, size))
				return (is_stack_sorted(structure->head_a));
			i--;
		}
	}
	while (i > 0)
	{
		update_order(&structure->head_a);
		if (sort_5(structure))
			break ;
		i--;
	}
	return (is_stack_sorted(structure->head_a));
}

void	push_swap(t_struct *structure, int size)
{
	if (structure->head_a && is_stack_sorted(structure->head_a))
	{
		printf("Already sorted!\n");
		return ;
	}
	if (size <= 5)
		sort_in_a(structure, size);
	if (is_stack_sorted(structure->head_a))
	{
		printf("stack_a is sorted!\n");
		return ;
	}
	else
	{
		printf("need stack_b\n");
		// while (!is_stack_sorted(structure->head_a))
		// call_b(structure, size);
	}
	// if (is_stack_sorted(structure->head_a))
	// {
	// 	printf("stack_a is sorted!\n");
	// 	return ;
	// }
	// else
	// 	printf(" :(");
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
		return (write (2, "Error\n", 6));
	if (check_errors(elements_count, list))
		return (write (2, "Error\n", 6));
	structure = init_struct(list, elements_count);
	if (argc == 2)
		free_tab(list);
	if (!structure)
		return (err_handling(structure), 0);
	push_swap(structure, structure->count);
	return (free_struct(structure), 0);
}
//for i in {1..500}; do echo $i; done | sort -R | tr '\n' ' '
