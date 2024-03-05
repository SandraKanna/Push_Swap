/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/03/05 18:08:43 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_struct	*init_b(t_struct *structure, int arr_size)
{
	t_node	*temp;
	int		i;
	int		*err = NULL;
	
	if (structure->count >= 5)
		arr_size /= 5;
	structure->head_b = malloc (sizeof(t_node) * (arr_size));
	if (!structure->head_b)
		err_handling(structure);
	structure->head_b = NULL;
	i = 0;
	while (i < arr_size)
	{
		temp = structure->head_a;
		while ((temp->rank && (temp->rank < structure->head_a->next->rank 
			&& temp->rank < structure->head_a->last->rank)))
			pb (&temp, &structure->head_b, i, err);
		if (err)
			return (NULL);
		i++;
	}
	return (structure);
}

// void	merge_ab(t_struct *a, t_struct **b)
// {

// }

int	sort_ops_a(t_struct *structure, int set_size)
{
	int	next;
	int	prev;
	int	last;
	int	head;

	if (is_stack_sorted(structure->head_a))
		return (1);
	update_rank_a(structure->head_a, set_size);
	head = structure->head_a->rank;
	next = structure->head_a->next->rank;
	prev = structure->head_a->prev_to_last->rank;
	last = structure->head_a->last->rank;
	if (head == 1)
		return (head_1(next, prev, last, &structure->head_a));
	if (head == 2)
		return (head_2(next, prev, last, &structure->head_a));
	if (head == 3)
		return (head_3(next, prev, &structure->head_a));
	if (head == 4)
		return (head_4(next, last, &structure->head_a));
	if (head == 5)
	    return (head_5(next, prev, last, &structure->head_a));
	return (0);
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
		update_order(structure, 'a');
		if (sort_ops_a(structure, size))
			break ;
		i--;
	}
	return (is_stack_sorted(structure->head_a));
}

int	tiny_sort_a(t_struct *structure, int size)
{
	int	head;
	int	mid;

	if (size == 2)
		return (sa(&structure->head_a), 1);
	update_order(structure, 'a');
	update_rank_a(structure->head_a, size);
	head = structure->head_a->rank;
	mid = structure->head_a->next->rank;
	if (head <= 2)
	{
		if (mid == 1)
			sa(&structure->head_a);
		else
			rra(&structure->head_a);
	}
	else if (head == 3)
	{
		if (mid == 1)
			ra(&structure->head_a);
		else
			sa(&structure->head_a);
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
		init_b(structure, size);
	}
	if (structure->head_b)
		free_b(&structure->head_b);
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
		return (err_handling(structure), 0); //return (0) ?
	push_swap(structure, structure->count);
	return (free_struct(structure), 0);
}
