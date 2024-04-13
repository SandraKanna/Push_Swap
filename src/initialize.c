/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:16:53 by skanna            #+#    #+#             */
/*   Updated: 2024/03/18 13:15:44 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../Includes/push_swap.h"
#include "push_swap.h"

int	create_group(t_struct *structure, int iter, int size, int group)
{
	int	biggest;
	int	smallest;
	int	mid;
	int	i;

	biggest = size * group;
	mid = (biggest - (size / 2));
	i = 0;
	printf("creating group: %i  biggest: %i  mid: %i\n", group, biggest, mid);
	while (i < size && count_nodes(structure->head_b) < (size * group))
	{
		smallest = find_smallest(structure->head_a, count_nodes(structure->head_a));
		if (structure->head_a->rank <= biggest)
		{
			push_to_stack(structure, 'b');
			if (structure->head_b->rank <= mid)
				rotate_up_stack(structure, 'b');
			i++;
		}
		else
			best_rotation(structure, smallest, 'a');
	}
	structure->batch_size[iter] = i;
	printf("\n---  iteration: %i  batch size init: %i---\n", iter, structure->batch_size[iter]);
	return (count_nodes(structure->head_a));
}

int	init_batch(t_struct *structure)
{
	int	n;
	int	total_batches;

	n = structure->count;
	structure->batch_size = NULL;
	total_batches = 0;
	while (n > 3)
	{
		total_batches += get_bit_len(n);
		n /= get_bit_len(n);
	}
	printf("\n--- total batches : %i ---\n", total_batches);
	structure->batch_size = malloc(sizeof(int *) * total_batches);
	if (!structure->batch_size)
		err_handling(structure);
	// structure->batch_size[total_batches] = 0;
	return (total_batches);
}

int	get_bit_len(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n >>= 1;
	}
	return (len);
}

void	rank_elems(t_node *list)
{
	t_node	*current;
	t_node	*temp;
	int		rank;

	current = list;
	while (current != NULL)
	{
		rank = 1;
		temp = list;
		while (temp != NULL)
		{
			if (current != temp)
			{
				if (current->value > temp->value)
					rank++;
			}
			temp = temp->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

t_struct	*init_struct(char **av, int count)
{
	t_struct		*structure;
	int				err;
	int				input;
	int				i;

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
		push(&structure->head_a, input, -1, &err);
		if (err)
			return (NULL);
		i--;
	}
	rank_elems(structure->head_a);
	structure->len_bits = get_bit_len(count);
	init_batch(structure);
	return (structure);
}
