/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:41:19 by skanna            #+#    #+#             */
/*   Updated: 2024/02/27 17:24:03 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	rank_set(t_node *list, int set_size)
{
	int	i;
	t_node	*last;
	t_node	*last_prev;
	t_node	*temp;

	last = find_last(list);
	last_prev = find_prev_last(list);
	i = 0;
	if (set_size > 5)
		set_size = 5;
	while (i < set_size)
	{
		list->rank = 1;
		temp = list;
		while (temp && temp->next != NULL)
		{
			if (temp->value > temp->next->value)
				temp->rank++;
			temp = temp->next;
		}
		i++;
	}
}

void	get_set(t_struct *structure, char c, int index, int set_size)
{
	t_node	*last;
	t_node	*last_prev;
	t_node	*temp;
	int		i;

	temp = structure->head_a;
	last = find_last(structure->head_a);
	last_prev = find_prev_last(structure->head_a);
	if (c == 'b')
	{
		last = find_last(structure->head_b[index]);
		last_prev = find_prev_last(structure->head_b);
		temp = structure->head_b;
	}
	i = 0;
	while (temp != NULL && i < set_size)
	{
		structure->head_a = temp->value;
		temp = temp->next;
		i++;
	}

	if (last != NULL)
		structure->set[i++] = last->value;

	if (last_prev != NULL)
		structure->set[i] = last_prev->value;
	if (!tag_values(structure, set_size))
		err_handling(structure);
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
	*structure->head_b = NULL;
	return (structure);
}
