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
	last = find_last(structure->head_a);
	if (size == 3)
	{
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

void	sort_in_a(t_struct *structure, int size)
{
	int		i;

	if (size <= 3)
		return (tiny_sort_a(structure));
	i = size + 2;
	while (i > 0)
	{
		update_order(structure, 'a');
		if (sort_ops_a(structure, size))
			return ;
		i--;
	}
}

// void	call_b(t_struct *structure, int arr_size)
// {
// 	int	i;

// 	structure->head_b = malloc (sizeof(t_node) * (arr_size));
// 	if (!structure->head_b)
// 		err_handling(structure);
// 	structure->head_b = NULL;
// 	i = 0;
// 	while (i < arr_size)
// 	{
// 		if ()
// 		 return ;
// 	}

// }

// void	merge_ab(t_struct *a, t_struct **b)
// {

// }

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
		return ;
	// else
	// {
	// 	size = size / 5;
	// 	call_b(structure, size);
	// }
	if (structure->head_b)
		free_b(&structure->head_b);
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
		return (err_handling(structure), 0); //return (0) ?
	push_swap(structure, structure->count);
	return (free_struct(structure), 0);
}
