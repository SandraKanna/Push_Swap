/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/02/27 17:52:11 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	tiny_sort_a(t_struct *structure)
{
	int		size;
	t_node	*last;

	//printf("test list size: %i\n", structure->count);
	size = structure->count;
	if (size == 2)
		return (sa(&structure->head));
	last = find_last(structure->head);
	if (size == 3)
	{
		if (structure->head->value < last->value)
		{
			sa(&structure->head);
			if (!is_stack_sorted(structure->head))
				return (ra(&structure->head));
		}
		else if (structure->head->value < structure->head->next->value)
			return (rra(&structure->head));
		else if (structure->head->value > last->value)
		{
			ra(&structure->head);
			if (!is_stack_sorted(structure->head))
				return (sa(&structure->head));	
		}
	}
}

// void	merge_ab(t_struct *a, t_struct **b)
// {
	
// }

void	push_swap(t_struct *a, int size)
{
	t_struct	**b;
	t_node		*last;
	int			i;

	if (a->head && is_stack_sorted(a->head))
	{
		printf("Already sorted!\n");
		return ;
	}
	if (a->count <= 3)
		tiny_sort_a(a);
	b = NULL;
	// i = size / 5;
	i = 0;
	// if (i > 1)
	while ((size / 5) > 1)
	{
		if (size > 7)
			get_set_a(a, 7);
		else
			get_set_a(a, size);
		// printf("WORK IN PROGRESS...\n");
		last = find_last(a->head);
		if (a->tags[i] != 1)
		{
			if (a->head->value > a->head->next->value)
			{
				if (a->head->value > last->value)
					rra(&a->head);
				else
					sa (&a->head);
			}
		}
		b[i] = initialize_b(a, 5);
		if (!b[i])
			err_handling_b(b, a);
		a->count -= 5;
		size -= 5;
		// push_swap(a, size - 5);
	}
	// merge_ab(a, b);
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
	if (argc == 2)
		free_tab(list);
	if (!a)
		return (err_handling(a), 0);
	push_swap(a, a->count);
	return (free_struct(a), 0);
}
