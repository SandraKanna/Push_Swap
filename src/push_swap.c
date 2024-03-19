/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/18 18:35:55 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_direction(int size, int position)
{
	int	mid;

	mid = size / 2;
	if (position <= mid)
		return (1);
	else
		return (2);
}

void	go_to_target(t_struct *structure, int direction, int target_pos)
{
	int	rotations_needed;

	rotations_needed = count_nodes(structure->head_a) - target_pos + 1;
	if (direction == 1)
	{
		while (target_pos > 1)
		{
			ra(&(structure->head_a));
			target_pos--;
		}
	}
	else if (direction == 2)
	{
		while (rotations_needed > 0)
		{
			rra(&(structure->head_a));
			rotations_needed--;
		}
	}
}

void	merge_ab(t_struct *structure)
{
	int	err;

	while (structure->head_b != NULL)
	{
		err = 0;
		pa(&structure->head_a, &structure->head_b, &err);
		if (err)
			err_handling(structure);
		structure->head_a->last = find_last(structure->head_a);
		if (structure->head_a->value > structure->head_a->last->value)
			ra(&(structure->head_a));
		else if (structure->head_a->value > structure->head_a->next->value && structure->head_a->value < structure->head_a->next->next->value)
			sa(&(structure->head_a));
	}
}

void	call_b(t_struct *structure, int start_group, int end_group)
{
	int		cur_pos;
	int		group_of_current;
	int		direction;
	t_node	*current;
	int		err;

	if (start_group > end_group)
		return ;
	current = structure->head_a;
	while (current != NULL && count_nodes(structure->head_a) > 3)
	{
		err = 0;
		cur_pos = find_position(structure->head_a, current->value);
		group_of_current = find_group(structure->count, current->rank);
		if (group_of_current == start_group)
		{
			direction = rotate_direction(count_nodes(structure->head_a), cur_pos);
			go_to_target(structure, direction, cur_pos);
			pb(&structure->head_a, &structure->head_b, &err);
			if (err)
				err_handling(structure);
			if (structure->head_b->next != NULL && structure->head_b->value < structure->head_b->next->value)
				sb(&(structure->head_b));
			current = structure->head_a;
		}
		else
			current = current->next;
	}
	call_b(structure, start_group + 1, end_group);
}


void	push_swap(t_struct *structure, int size)
{
	int	total_groups;

	if (structure->head_a && is_stack_sorted(structure->head_a))
		return ;
	if (size <= 3)
	{
		while(!is_stack_sorted(structure->head_a))
			tiny_sort(structure);
	}
	// if (is_stack_sorted(structure->head_a))
		// printf("stack_a is sorted!\n");
	else if (size <= 99)
	{
		// printf("need stack_b\n");
		//while (!is_stack_sorted(structure->head_a))
		total_groups = 11;
		call_b(structure, 1, total_groups);
		t_node *temp = structure->head_b;
		int i = 0;
		while (temp != NULL && i < 100)
		{
			printf("b[%i]: %i\n", i, temp->value);
			i++;
			temp = temp->next;
		}
		tiny_sort(structure);
		t_node *printme = structure->head_a;
		while (printme != NULL)
		{
			printf("%i\n", printme->value);
			printme = printme->next;
		}
		merge_ab(structure);
	}
	if (is_stack_sorted(structure->head_a)
		&& (count_nodes(structure->head_a) == structure->count))
		printf("stack_a is sorted!\n");
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
	t_node *printme = structure->head_a;
	while (printme != NULL)
	{
		printf("%i\n", printme->value);
		printme = printme->next;
	}
	return (free_struct(structure), 0);
}
//for i in {-10..20}; do echo $i; done | sort -R | tr '\n' ' '
