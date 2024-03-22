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

void	init_bit_array(t_struct *structure, int size)
{
	int		i;
	int		temp_rank;
	t_node	*cur;

	cur = structure->head_a;
	structure->len_bits = get_bit_len(size);
	while (cur != NULL)
	{
		temp_rank = cur->rank;
		cur->bit = malloc (sizeof (int) * structure->len_bits);
		if (!cur->bit)
			err_handling(structure);
		i = structure->len_bits - 1;
		while (i >= 0)
		{
			cur->bit[i] = temp_rank & 1;//store the LSB
			temp_rank >>= 1;//move bits to the right to check the next bit
			// printf("bit[%i]: %i ", i, cur->bit[i]);
			i--;//move to the next storage column
		}
		cur = cur->next;
	}
	t_node *printme = structure->head_a;
	while (printme != NULL)
	{
		int j = 0;
		printf("value: %i -> ", printme->value);
		while (j < structure->len_bits)
		{
			printf("bit[%i]: %i ", j, printme->bit[j]);
			j++;
		}
		printf("\n");
		printme = printme->next;
	}
}

t_struct	*init_struct(char **av, int count)
{
	t_struct		*structure;
	int				err;
	int				input;
	int	i;

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
	init_bit_array(structure, structure->count);
	structure->head_a->last = find_last(structure->head_a);
	// t_node *printme = structure->head_a;
	// while (printme != NULL)
	// {
	// 	printf("%i\n", printme->value);
	// 	printme = printme->next;
	// }
	return (structure);
}
