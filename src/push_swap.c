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

void	merge_ab(t_struct *structure)
{
	int	mid;
	int	err;

	mid = structure->count / 2;
	err = 0;
	while (structure->head_b != NULL)
	{
		if (structure->head_b->next != NULL && structure->head_b->rank > mid
			&& structure->head_b->rank < structure->head_b->next->rank)
			sb(&structure->head_b);
		pa(&structure->head_a, &structure->head_b, &err);
		if (err)
			err_handling(structure);
	}
}

void	call_b(t_struct *structure)
{
	// int	mid;
	int	temp;
	int	err;

	// mid = structure->count / 2;
	temp = structure->count - 2;
	err = 0;
	while (structure->head_a != NULL)
	{
		if (structure->head_a->rank >= temp)
			ra(&structure->head_a);
		else
		{
			pb(&structure->head_a, &structure->head_b, &err);
			if (err)
				err_handling(structure);
		}
		if (structure->head_a->next->next->next == NULL )
			break ;
	}
	while (!is_stack_sorted(structure->head_a))
		tiny_sort(structure);
	merge_ab(structure);
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
		while (!is_stack_sorted(structure->head_a))
			call_b(structure);
	}
	if (is_stack_sorted(structure->head_a))
	{
		printf("stack_a is sorted!\n");
		return ;
	}
	else
		printf(" :(");
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
