/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:06:55 by skanna            #+#    #+#             */
/*   Updated: 2024/02/24 16:22:26 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	is_set_b_sorted(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] < array[i + 1])
			return (0);
		//printf("test sort index: %i\n", array[i]);
		i++;
	}
	return (1);
}

t_struct	*initialize_b(t_struct *a, int size)
{
	t_struct	*b;
	// int			input;
	int			i;
	int			err;

	b = malloc (sizeof(t_struct));
	if (!b)
		return (NULL);
	b->count = size;
	b->head = NULL;
	i = 0;
	while (i < size)
	{
		pb(&a->head, &b->head, &err);
		if (err)
			return (NULL);
		i++;
	}
	get_set(b, size);
	return (b);
}

void	tiny_sort_b(t_struct *structure)
{
	int	size;

	size = structure->count;
	if (size == 2)
		return (sa(&structure->head));
	if (size == 3)
	{
		rra(&structure->head);
		return (sa(&structure->head));
	}
}

// void	call_b(t_struct *structure, int size)
// {
// 	int	next_size;

// 	next_size = size / 5;
// 	if (next_size > 0)
// 		call_b(structure, size / 5);
// 	initialize_b(structure, size);
// 	//initialise the structure: diff table of lists
// 	//
// }

// void	tag_values_b(t_struct *structure, int set_size)
// {
// 	int	i;
// 	int	j;
// 	int	rank_b;

// 	structure->tags = malloc (sizeof(int) * set_size);
// 	if (!structure->tags)
// 		err_handling(structure);
// 	i = 0;
// 	while (i < set_size)
// 	{
// 		j = 0;
// 		rank_b = 1;
// 		while (j < set_size)
// 		{
// 			if (structure->set[i] > structure->set[j])
// 				rank_b++;
// 			j++;
// 		}
// 		structure->tags[i] = rank_b;
// 		i++;
// 	}
// }
