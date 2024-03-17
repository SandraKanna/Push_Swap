/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/15 15:34:05 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_ab(t_struct *structure, int count_b)
{
	int	err;
	int	head_group;
	int	big;
	int	small;

	count_b = count_nodes(structure->head_b);
	if (count_b == 0)
		return ;
	rank_elems(structure->head_b);
	head_group = find_group(count_b, structure->head_a->rank);
	err = 0;
	big = find_biggest(structure->head_a);
	small = find_smallest(structure->head_a);
	if (head_group )	
		pa(&structure->head_a, &structure->head_b, &err);
	if (err)
		err_handling(structure);
	if (structure->head_a->next != NULL
		&& structure->head_a->value > structure->head_a->next->value)
		ra(&structure->head_a);
	merge_ab(structure, count_b);
}

int	rotate_direction(t_node	*list, int size, int big, int small)
{
	int	quad_big;
	int	quad_small;

	quad_big = quadrant(size, big);
	quad_small = quadrant(size, small);
	if (quad_big <= 2)
	{
		if (quad_small <= 2)
			return (1); //ra
		else if (big > (size - small))
			return (2); //rra
	}
	else if (quad_big > 2)
	{
		if (quad_small > 2)
			return (2); //rra
		else if ((size - big) > small)
			return (1); //ra
	}
}

void	call_b(t_struct *structure, int count)
{
	int	big;
	int	small;
	int	head_group;

	count = count_nodes(structure->head_a);
	rank_elems(structure->head_a);
	big = find_biggest(structure->head_a);
	small = find_smallest(structure->head_a);
	head_group = find_group((count / 2), structure->head_a->rank);
	if (count <= 4)
		sort_in_a(structure, count);
	else
	{
		if (head_group == 1 || head_group == 4)
			push_sort_b(structure, head_group);
		else if (rotate_direction(structure->head_a, count, big, small) == 1)
			ra(&structure->head_a);
		else if (rotate_direction(structure->head_a, count, big, small) == 2)
			rra(&structure->head_a);
		call_b(structure, count);
	}
	merge_ab(structure, div);
}

int	sort_in_a(t_struct *structure, int size)
{
	int	i;

	i = size + 2;
	if (size <= 3)
	{
		while (i > 0)
		{
			if (tiny_sort(structure))
				return (is_stack_sorted(structure->head_a));
			i--;
		}
	}
	while (i > 0)
	{
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
	// if (is_stack_sorted(structure->head_a)
	// 	&& (count_nodes(structure->head_a) == structure->count))
	// 	printf("stack_a is sorted!\n");
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
	// t_node *printme = structure->head_a;
	// while (printme != NULL)
	// {
	// 	printf("%i\n", printme->value);
	// 	printme = printme->next;
	// }
	return (free_struct(structure), 0);
}
//for i in {-100..200}; do echo $i; done | sort -R | tr '\n' ' '
