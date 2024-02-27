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
	t_node	*last;
	int		size;

	size = structure->count;
	if (size == 2)
		return (sa(&structure->head_a));
	if (size == 3)
	{
		last = find_last(structure->head_a);
		if (structure->head_a->value < last->value)
		{
			sa(&structure->head_a);
			if (!is_stack_sorted(structure->head_a))
				return (ra(&structure->head_a));
		}
		else if (structure->head_a->value < structure->head_a->next->value)
			return (rra(&structure->head_a));
		else if (structure->head_a->value > last->value)
		{
			ra(&structure->head_a);
			if (!is_stack_sorted(structure->head_a))
				return (sa(&structure->head_a));
		}
	}
}

void	sort(t_struct *structure, int size, char c)
{
	int		size;
	t_node	*last;

	i = 0;
	last = find_last(structure->head_a);
	if (size == 4)
	{
		
	}
	// if (i > 1)
	while ((size / 5) > 1)
	{

	}
	
}

// void	merge_ab(t_struct *a, t_struct **b)
// {

// }

void	push_swap(t_struct *structure, int size)
{
	t_node	**b;
	t_node	*last;
	int		i;

	if (structure->head_a && is_stack_sorted(structure->head_a))
	{
		printf("Already sorted!\n");
		return ;
	}
	if (structure->count <= 3)
		return (tiny_sort_a(structure));
	rank_set(structure->head_a, size);
	b = NULL;
	sort (structure, size);
	// merge_ab(a, b);
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
	structure = init_struct(list, elements_count);
	if (argc == 2)
		free_tab(list);
	if (!structure)
		return (err_handling(structure), 0);
	push_swap(structure, structure->count);
	return (free_struct(main), 0);
}
