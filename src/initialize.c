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
			if (structure->set[i] > structure->set[j])
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
	temp = structure->head_a;
	while (temp != NULL && i < set_size)
	{
		structure->set[i] = temp->value;
		temp = temp->next;
		i++;
	}
	last = find_last(structure->head_a);
	if (last != NULL)
		structure->set[i++] = last->value;
	last_prev = find_prev_last(structure->head_a);
	if (last_prev != NULL)
		structure->set[i] = last_prev->value;
	tag_values_a(structure, set_size);
	structure->sorted = is_set_sorted(structure->set, set_size);
}

t_struct	*struct_init(char **av, int count)
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
	if (structure->count > 7)
		get_set(structure, 7);
	else
		get_set(structure, structure->count);
	return (structure);
}
