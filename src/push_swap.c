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
		return (sa(&structure->head));
	if (size == 3)
	{
		rra(&structure->head);
		if (!is_stack_sorted(structure->head))
			return (sa(&structure->head));
	}
}

void	merge_ab(t_struct *a, t_struct b)
{

}

void	push_swap(t_struct *a, int size)
{
	t_struct	**b;
	int			i;

	if (a->head && is_stack_sorted(a->head))
	{
		printf("Already sorted!\n");
		return ;
	}
	if (a->count <= 3)
		tiny_sort_a(a);
	i = size / 5;
	if (i > 1)
	{
		// printf("WORK IN PROGRESS...\n");
		b[i] = initialize_b(a, 5);
		if (!b[i])
			err_handling_b(b, a);
		// size -= 5;
		push_swap(a, size - 5);
		merge_ab(a, *b[i]);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_struct	*a;
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
	a = initialize_a(list, elements_count);
	if (!a)
		return (err_handling(a), 0);
	if (argc == 2)
		free_tab(list);
	push_swap(a, a->count);
	return (free_struct(a), 0);
}
