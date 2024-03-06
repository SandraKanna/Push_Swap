/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/06 19:09:31 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	merge_ab(t_struct *structure, int index)
{
	t_node	*b;
	int		err;
	
	err = 0;
	b = structure->head_b[index];
	while (b != NULL)
	{
		update_order(structure, 'b', index);
		if (b->next != NULL && b->last != NULL)
		{
			if ((b->value < b->next->value) 
				&& (b->next->value < b->last->value))
				sb(&b);
			else if ((b->value < b->last->value)
				&& (b->last->value < b->next->value))
				rrb(&b);
		}
		pa(&structure->head_a, &b, &err);
		if (err)
			err_handling (structure);
	}
}

	// while (head_b[index] != NULL)
	// {
	// 	update_order(structure, 'b', i);
	// 	b = structure->head_b[index];
	// 	if (b != NULL && b[i] != NULL && b[i]->next != NULL 
	// 		&& b[i]->last != NULL)
	// 	{
	// 		if ((b[i]->value < b[i]->next->value) 
	// 			&& (b[i]->next->value < b[i]->last->value))
	// 			sb(&b[i]);
	// 		else if ((b[i]->value < b[i]->last->value)
	// 			&& (b[i]->last->value < b[i]->next->value))
	// 			rrb(&b[i]);
	// 		pa(&structure->head_a, &b[i], &err);
	// 		if (err)
	// 			err_handling (structure);
	// 	}
	// 	i++;
	// }

void	call_b(t_struct *structure, int size)
{
	int		i;

	if (structure->count >= 5)
		size /= 5;
	structure->head_b = malloc (sizeof(t_node *) * (size + 1));
	if (!structure->head_b)
		err_handling(structure);
	i = 0;
	while (i <= size)
		structure->head_b[i++] = NULL;
	i = 0;
	while (i < size)
		fill_b(structure, i++);
	i = 0;
	while (structure->head_b != NULL && i < size)
		merge_ab(structure, i++);
}

int	sort_in_a(t_struct *structure, int size)
{
	int	i;

	i = size + 3;
	if (size <= 3)
	{
		while (i > 0)
		{
			if (tiny_sort_a(structure, size))
				return (is_stack_sorted(structure->head_a));
			i--;
		}
	}
	while (i > 0)
	{
		update_order(structure, 'a', -1);
		if (sort_ops_a(structure, size))
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
		call_b(structure, size);
	}
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
	// t_node *temp = structure->head_b[0];
	// while (temp != NULL)
	// {	printf ("b[0]: %i\n", temp->value);
	// 	temp = temp->next;
	// }
	// temp = structure->head_b[1];
	// while (temp != NULL)
	// {	printf ("b[1]: %i\n", temp->value);
	// 	temp = temp->next;
	// }
	return (free_struct(structure), 0);
}
//for i in {1..500}; do echo $i; done | sort -R | tr '\n' ' '
