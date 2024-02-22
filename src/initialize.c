/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:41:19 by skanna            #+#    #+#             */
/*   Updated: 2024/02/22 18:26:20 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"


void	tag_values_a(t_struct *structure, int set_size)
{
	int	i;
	int	j;
	int	rank_a;

	structure->tags = malloc (sizeof(int) * set_size);
	if (!structure->tags)
		err_handling(structure);
	i = 0;
	while (i < set_size)
	{
		j = 0;
		rank_a = 1;
		while (j < set_size)
		{
			if (structure->set[i] < structure->set[j])
				rank_a++;
			j++;
		}
		structure->tags[i] = rank_a;
		i++;
	}
}

void	get_set(t_struct *structure, int set_size)
{
	t_node	*last;
	t_node	*last_prev;
	t_node	*temp;
	int		i;

	structure->set = malloc (sizeof(int *) * set_size);
	if (!structure->set)
		err_handling(structure);
	i = 0;
	temp = structure->head;
	while (temp != NULL && i < set_size)
	{
		structure->set[i] = temp->value;
		temp = temp->next;
		i++;
	}
	last = find_last(structure->head);
	if (last != NULL)
		structure->set[i++] = last->value;
	last_prev = find_prev_last(structure->head);
	if (last_prev != NULL)
		structure->set[i] = last_prev->value;
	tag_values_a(structure, set_size);
	index_sorted(structure->set, set_size);
}

t_struct	*initialize_a(char **av, int count)
{
	t_struct	*struct_a;
	int			input;
	int			i;
	int			err;

	struct_a = malloc (sizeof(t_struct));
	if (!struct_a)
		return (NULL);
	struct_a->count = count;
	struct_a->head = NULL;
	i = 0;
	err = 0;
	while (i < count)
	{
		input = ft_atoi(av[i]);
		push(&struct_a->head, input, &err);
		if (err)
			return (NULL);
		i++;
	}
	if (struct_a->count > 7)
		get_set(struct_a, 7);
	else
		get_set(struct_a, struct_a->count);
	return (struct_a);
}
