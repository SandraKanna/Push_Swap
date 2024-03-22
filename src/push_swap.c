/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/19 19:01:29 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_column_complete(t_node *list, int bit, int i)
{
	t_node	*cur;
	int		bit_cur;

	cur = list;
	while (cur != NULL)
	{
		bit_cur = cur->bit[i];
		if (bit_cur == bit)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
}

int	select_bit(t_node *list, int bit_count, int i)
{
	int		zeros;
	int		ones;
	int		bit_cur;
	t_node	*cur;

	zeros = 0;
	ones = 0;
	cur = list;
	while (cur != NULL)
	{
		bit_cur = cur->rank;
		if (bit_cur & (1 << (bit_count - i)))
			ones++;
		else
			zeros++;
		cur = cur->next;
	}
	if (max_value(zeros, ones) == 1)
		return (1);
	return (0);
}

void	radix_sort(t_struct *structure, int bit_column)
{
	int		bit;

	// bit = select_bit(structure->head_a, structure->len_bits, bit_column);
	bit = 1;

	printf("\n--- radix ---\n\n");
	sort_column(structure, count_nodes(structure->head_a), bit_column, bit);
	printf("count_a: %i, struct_count: %i\n", count_nodes(structure->head_a), structure->count);
	if (count_nodes(structure->head_a) == structure->count && bit_column == structure->len_bits - 1)
		return ;
	radix_sort(structure, ++bit_column);
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
	t_node *printme = structure->head_a;
	printf("\n--- final stack A ---\n");
	while (printme != NULL)
	{
		printf("A: %i\n", printme->value);
		printme = printme->next;
	}
	return (free_struct(structure), 0);
}

//for i in {-10..20}; do echo $i; done | sort -R | tr '\n' ' '
