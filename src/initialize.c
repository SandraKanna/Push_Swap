/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:16:53 by skanna            #+#    #+#             */
/*   Updated: 2024/03/15 10:45:56 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../Includes/push_swap.h"
#include "push_swap.h"

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
		push(&structure->head_a, input, -1, &err);
		if (err)
			return (NULL);
		i--;
	}
	rank_elems(structure->head_a);
	structure->head_a->last = find_last(structure->head_a);
	// t_node *printme = structure->head_a;
	// while (printme != NULL)
	// {
	// 	printf("%i\n", printme->value);
	// 	printme = printme->next;
	// }
	return (structure);
}
