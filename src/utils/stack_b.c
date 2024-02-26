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

t_node	*initialize_b(t_struct *structure, int size)
{
	t_node	**struct_b;
	t_node		*stack_b;
	int			len;

	struct_b = malloc (sizeof(t_node *) *);
	if (!structure)
		return (NULL);


}

void	tiny_sort_b(t_struct *structure)
{
	int	size;

	size = structure->count;
	if (size == 2)
		return (sa(&structure->head_a));
	if (size == 3)
	{
		rra(&structure->head_a);
		return (sa(&structure->head_a));
	}
}

void	call_b(t_struct *structure, int size)
{
	int	next_size;

	next_size = size / 5;
	if (next_size > 0)
		call_b(structure, size / 5);
    initialize_b(structure, size);
	//initialise the structure: diff table of lists
	//
}

void	tag_values_b(t_struct *structure, int set_size)
{
	int	i;
	int	j;
	int	rank_b;

	structure->tags = malloc (sizeof(int) * set_size);
	if (!structure->tags)
		err_handling(structure);
	i = 0;
	while (i < set_size)
	{
		j = 0;
		rank_b = 1;
		while (j < set_size)
		{
			if (structure->set[i] > structure->set[j])
				rank_b++;
			j++;
		}
		structure->tags[i] = rank_b;
		i++;
	}
}
