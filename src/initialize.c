/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:41:19 by skanna            #+#    #+#             */
/*   Updated: 2024/03/05 17:32:22 by skanna           ###   ########.fr       */
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
//update rank for b function

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

void	update_order(t_struct *structure, char c)
{
	t_node	*mid;
	t_node	*prev;
	t_node	*last;

	mid = find_mid_of_set(structure->head_a);
	structure->head_a->middle = mid;
	last = find_last(structure->head_a);
	structure->head_a->last = last;
	prev = find_prev_to_last(structure->head_a);
	structure->head_a->prev_to_last = prev;
	if (c == 'b')
	{
		mid = find_mid_of_set(*structure->head_b);
		(*structure->head_b)->middle = mid;
		last = find_last(*structure->head_b);
		(*structure->head_b)->last = last;
		prev = find_prev_to_last(*structure->head_b);
		(*structure->head_b)->prev_to_last = prev;
	}
}

t_struct	*init_struct(char **av, int count)
{
	t_struct	*structure;
	int			input;
	int			i;
	int			err;

	structure = malloc (sizeof(t_struct));
	if (!structure)
		return (NULL);
	structure->count = count;
	structure->head_a = NULL;
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
	structure->head_b = NULL;
	return (structure);
}
