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

int	is_set_a_sorted(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] > array[i + 1])
			return (0);
		//printf("test sort index: %i\n", array[i]);
		i++;
	}
	return (1);
}

int	*tag_values(t_struct *structure, int set_size)
{
	int	i;
	int	j;
	int	rank;

	structure->tags = malloc (sizeof(int) * set_size);
	if (!structure->tags)
		return (NULL);
	i = 0;
	while (i < set_size)
	{
		j = 0;
		rank = 1;
		while (j < set_size)
		{
			if (structure->set[i] > structure->set[j])
				rank++;
			j++;
		}
		structure->tags[i] = rank;
		i++;
	}
	return (structure->tags);
}

void	get_set_a(t_struct *a, int set_size)
{
	t_node	*last;
	t_node	*last_prev;
	t_node	*temp;
	int		i;

	a->set = malloc (sizeof(int *) * set_size);
	if (!a->set)
		err_handling(a);
	i = 0;
	temp = a->head;
	while (temp != NULL && i < set_size)
	{
		a->set[i] = temp->value;
		temp = temp->next;
		i++;
	}
	last = find_last(a->head);
	if (last != NULL)
		a->set[i++] = last->value;
	last_prev = find_prev_last(a->head);
	if (last_prev != NULL)
		a->set[i] = last_prev->value;
	if (!tag_values(a, set_size))
		err_handling(a);
	a->sorted = is_set_a_sorted(a->set, set_size);
}

t_struct	*initialize_a(char **av, int count)
{
	t_struct	*a;
	int			input;
	int			i;
	int			err;

	a = malloc (sizeof(t_struct));
	if (!a)
		return (NULL);
	a->count = count;
	a->head = NULL;
	i = count - 1;
	err = 0;
	while (i >= 0)
	{
		input = ft_atoi(av[i]);
		push(&a->head, input, &err);
		if (err)
			return (NULL);
		i--;
	}
	// if (a->count > 7)
	// 	get_set_a(a, 7);
	// else
	// 	get_set_a(a, a->count);
	return (a);
}
