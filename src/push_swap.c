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

void	merge_ab(t_struct *structure)
{
	int	err;
	
	err = 0;
	while (!is_stack_sorted(structure->head_a))
		tiny_sort(structure);
	while (structure->head_b != NULL)
	{
		pa(&structure->head_a, &structure->head_b, &err);
		if (err)
			err_handling(structure);
	}
}

void	call_b(t_struct *structure, float *mult)
{
	int	piv;
	int	err;

	err = 0;
	while (structure->head_a != NULL && structure->head_a->next != NULL
		&& structure->head_a->next->next != NULL)
	{
		piv = (structure->count * mult[0]);
		if (structure->head_a->rank >= piv)
			ra(&structure->head_a);
		else
		{
			pb(&structure->head_a, &structure->head_b, &err);
			if (err)
				err_handling(structure);
			rank_elems(structure->head_a);
			structure->head_a->last = find_last(structure->head_a);
			piv = (count_nodes(structure->head_a) * mult[1]);
			sort_b(structure, piv);
		}
	}
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
		float mult[2] = {0.6, 0.2};
		// printf("need stack_b\n");
		while (!is_stack_sorted(structure->head_a))
		{
			// int i = 0;
			// while (i < 3)
			// {
				rank_elems(structure->head_a);
				structure->head_a->last = find_last(structure->head_a);
				call_b(structure, mult);
				// i++;
			// }
		}
	}
	if (is_stack_sorted(structure->head_a))
	{
	//	printf("stack_a is sorted!\n");
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
