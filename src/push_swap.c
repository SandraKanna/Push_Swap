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

void	merge_ab(t_struct *structure, float div)
{
	int	err;
	int	piv;
	int	size_b;
	int	i;

	sort_in_a(structure, count_nodes(structure->head_a));
	while (structure->head_b != NULL)
	{
		rank_elems(structure->head_b);
		size_b = count_nodes(structure->head_b);
		piv = (size_b * div);
		if (piv == 0)
			piv = 1;
		err = 0;
		i = 0;
		while (i < (piv * 2))
		{
			if (structure->head_b->rank > piv)
				rb(&structure->head_b);
			else	
			{
				pa(&structure->head_a, &structure->head_b, &err);
				if (err)
					err_handling(structure);
				i++;
			}
		}
	}
}

void	call_b(t_struct *structure, float div)
{
	int		piv;
	int		size_a;
	int		i;

	size_a = structure->count;
	while (size_a > 4)
	{
		size_a = count_nodes(structure->head_a);
		i = 0;
		rank_elems(structure->head_a);
		piv = (size_a * div);
		while (i < (piv * 2) && size_a > 4)
		{
			if (structure->head_a->rank > piv && structure->head_a->rank < (size_a - piv))
				ra(&structure->head_a);
			else
			{
				push_sort_b(structure, piv);
				i++;
			}
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

	div = 0.25;
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
//for i in {-100..200}; do echo $i; done | sort -R | tr '\n' ' '
