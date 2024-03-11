/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:16:53 by skanna            #+#    #+#             */
/*   Updated: 2024/03/11 19:51:49 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rank_set(t_node **nodes, int set_size)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < set_size)
	{
		if (nodes[i] != NULL)
		{
			rank = 1;
			j = 0;
			while (j < set_size)
			{
				if (i != j && nodes[j] != NULL)
				{
					if (nodes[i]->value > nodes[j]->value)
						rank++;
				}
				j++;
			}
			nodes[i]->rank = rank;
		}
		i++;
	}
}

int	update_rank_a(t_node *list, int set_size)
{
	t_node	**set;

	if (set_size > 5)
		set_size = 5;
	set = malloc (sizeof(t_node *) * set_size);
	if (!set)
		return (0);
	set [0] = list;
	set [1] = list->next;
	if (set_size == 3)
		set [2] = find_last(list);
	else
	{
		set [2] = find_prev_to_last(list);
		set [3] = find_last(list);
	}
	if (set_size == 5)
		set [4] = find_mid_of_set(list);
	rank_set(set, set_size);
	free (set);
	return (1);
}

int	tiny_sort_a(t_struct *structure, int size)
{
	int	head;
	int	mid;

	if (size == 2)
		return (sa(&structure->head_a), 1);
	update_order(&structure->head_a);
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
	prev = structure->head_a->prev->rank;
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

void	rank_elems(t_node **nodes, int size)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < size)
	{
		if (nodes[i] != NULL)
		{
			rank = 1;
			j = 0;
			while (j < size)
			{
				if (i != j && nodes[j] != NULL)
				{
					if (nodes[i]->value > nodes[j]->value)
						rank++;
				}
				j++;
			}
			nodes[i]->rank = rank;
		}
		i++;
	}
}

t_struct	*init_struct(char **av, int count)
{
	t_struct	*structure;
	int			err;
	int			input;
	int			i;

	structure = malloc (sizeof(t_struct));
	if (!structure)
		return (NULL);
	structure->count = count;
	structure->head_a = NULL;
	structure->head_b = NULL;
	i = count - 1;
	err = 0;
	while (i >= 0)
	{
		input = ft_atoi(av[i]);
		push(&structure->head_a, input, &err);
		if (err)
			return (NULL);
		i--;
	}
	rank_elems(&structure->head_a, count);
	i = 0;
	t_node *temp = structure->head_a;
	while (structure->head_a != NULL)
	{
		printf ("rank[%i]: %i\n", i, temp->rank);
		i++;
		temp = temp->next;
	}
	return (structure);
}
