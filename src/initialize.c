/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:16:53 by skanna            #+#    #+#             */
/*   Updated: 2024/04/16 20:52:58 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

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
	return (structure);
}
