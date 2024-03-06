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

#include "../Includes/push_swap.h"

void	fill_b(t_struct *structure, int index)
{
	t_node	*temp;
	int		j;
	int		err;

	j = 0;
	err = 0;
	while (j < 5)
	{
		update_order(structure, 'a', -1);
		temp = structure->head_a;
		if (temp->value > temp->next->value
			&& temp->next->value < temp->last->value)
			sa(&structure->head_a);
		else if (temp->value > temp->last->value
			&& temp->last->value < temp->next->value)
			rra(&structure->head_a);
		pb (&structure->head_a, &structure->head_b[index], &err);
		if (err)
			err_handling (structure);
		if (structure->head_a->next->next == NULL)
			break ;
		j++;
	}
}

