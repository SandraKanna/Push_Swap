/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/28 14:48:40 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_struct *structure, int start)
{
	int	j;
	int	cur_bit;
	int	count;
	int	rotations;
	int	move_to_b;

	count = count_nodes(structure->head_a);
	move_to_b = count_bits(structure->head_a, 0, start);
	rotations = count - move_to_b;
	j = 0;
	// printf("\n--- stack A0 ---\n");
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("a: %i\n", printme->rank);
	// if (structure->count <= 6)
	// {
	// 	while (j < (structure->count / 2))
	// 	{
	// 		if (structure->head_a->rank <= structure->count / 2)
	// 		{
	// 			push_to_stack(structure, 'b');
	// 			if (structure->head_b->next != NULL && structure->head_b->rank < structure->head_b->next->rank)
	// 				rotate_down_stack(structure, 'b');
	// 		}
	// 		else
	// 			rotate_up_stack(structure, 'a');
	// 		j++;
	// 	}
	// 	while (!is_stack_sorted(structure->head_a))
	// 		tiny_sort(structure);
	// 	while (structure->head_b != NULL)
	// 	{
	// 		push_to_stack(structure, 'a');
	// 		// if (structure->head_a->rank > structure->head_a->next->rank)
	// 		// 	rotate_up_stack(structure, 'a');
	// 	}
	// 	return ;
		
	// }
	while (j < count)
	{
		cur_bit = (structure->head_a->rank >> start) & 1;
		if (cur_bit == 0)
		{
			push_to_stack(structure, 'b');
			move_to_b--;
		}
		else
		{
			if (move_to_b == 0)
			{
				if (rotations == count_nodes(structure->head_a))	
					break;
				if (rotations == (count_nodes(structure->head_a) - 1))
				{
					rotate_down_stack(structure, 'a');
					break;
				}
			}
			rotate_up_stack(structure, 'a');
			rotations--;
		}
		j++;
	}
	start += 1;
	// printf("\n--- stack A1 ---\n");
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("a: %i\n", printme->rank);
	// printf("\n--- stack B1 ---\n");
	// for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
	// 	printf("B: %i\n", printme->rank);
	sort_b(structure, start);
	// printf("\n--- stack A2 ---\n");
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("a: %i\n", printme->rank);
	// printf("\n--- stack B2 ---\n");
	// for (t_node *printme = structure->head_b; printme != NULL; printme = printme->next)
	// 	printf("B: %i\n", printme->rank);
	if (structure->head_b != NULL)
		radix_sort(structure, start);
}

void	push_swap(t_struct *structure, int size)
{
	if (structure->head_a && is_stack_sorted(structure->head_a))
		return ;
	if (size <= 3)
	{
		while(!is_stack_sorted(structure->head_a))
			tiny_sort(structure);
	}
	else
	{
		radix_sort(structure, 0);
	}
	if (is_stack_sorted(structure->head_a)
		&& (count_nodes(structure->head_a) == structure->count))
		printf("stack_a is sorted!\n");
}

int	main(int argc, char **argv)
{
	t_struct		*structure;
	int	elements_count;
	char			**list;

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
	printf("\n--- final stack A ---\n");
	for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
		printf("A: %i\n", printme->rank);
	return (free_struct(structure), 0);
}

//for i in {0..100}; do echo $i; done | sort -R | tr '\n' ' '
