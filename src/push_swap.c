/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/13 18:29:51 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	merge_ab(t_struct *structure, float div)
{
	int		err;
	int		piv;

	while (!is_stack_sorted(structure->head_a))
		tiny_sort(structure);
	while (structure->head_b != NULL)
	{
		rank_elems(structure->head_b);
		piv = (count_nodes(structure->head_b) * div);
		err = 0;
		if (structure->head_b->rank < piv)
			rb(&structure->head_b);
		else
		{
			pa(&structure->head_a, &structure->head_b, &err);
			if (err)
				err_handling(structure);
		}
	}
}

void	call_b(t_struct *structure, float div)
{
	int		piv;
	int		size;
	int		err;

	size = structure->count;
	while (size > 3)
	{
		size = count_nodes(structure->head_a);
		rank_elems(structure->head_a);
		err = 0;
		piv = (size * div);
		if (structure->head_a->rank > piv)
			ra(&structure->head_a);
		else
		{
			pb(&structure->head_a, &structure->head_b, &err);
			if (err)
				err_handling(structure);
			sort_b(structure, div);
		}
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
	float	div;

	div = 0.5;
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
		while (!is_stack_sorted(structure->head_a))
			call_b(structure, div);
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
//for i in {-10..20}; do echo $i; done | sort -R | tr '\n' ' '
