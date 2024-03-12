/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/12 15:45:36 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	merge_ab(t_struct *structure)
{
	// int	mid;
	int	err;

	// mid = structure->count / 2;
	err = 0;
	while (structure->head_b != NULL)
	{
		structure->head_b->last = find_last(structure->head_b);
		if ((structure->head_b->next != NULL && structure->head_b->last != NULL)
			&& (structure->head_b->last->rank >= structure->head_b->next->rank && structure->head_b->last->rank >= structure->head_b->rank ))
			rrb(&structure->head_b);
		else if((structure->head_b->next != NULL && structure->head_b->last != NULL)
			&& (structure->head_b->next->rank > structure->head_b->rank ))
			sb(&structure->head_b);
		else
		{
			pa(&structure->head_a, &structure->head_b, &err);
			if (err)
				err_handling(structure);
		}
	}
}

void	call_b(t_struct *structure)
{
	int	mid;
	//int	quart;
	// int	temp;
	int	err;

	mid = (structure->count * 0.5) + 1;
	if (mid > 3)
		mid = (structure->count * 0.75);
//	quart = (structure->count * 0.75);
	// temp = structure->count - 2;
	// mid = (count_nodes(structure->head_a) / 2);
	err = 0;
	while (structure->head_a != NULL)
	{
		structure->head_a->last = find_last(structure->head_a);
		if (structure->head_a->rank >= mid)
			ra(&structure->head_a);
		else if (structure->head_a->rank < mid && structure->head_a->next->rank < structure->head_a->rank)
			sa(&structure->head_a);
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
		// printf("Already sorted!\n");
		return ;
	}
	if (size <= 5)
		sort_in_a(structure, size);
	if (is_stack_sorted(structure->head_a))
	{
		// printf("stack_a is sorted!\n");
		return ;
	}
	else
	{
		// printf("need stack_b\n");
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
		return (err_handling(structure), 0);
	push_swap(structure, structure->count);
	return (free_struct(structure), 0);
}
//for i in {-10..20}; do echo $i; done | sort -R | tr '\n' ' '
