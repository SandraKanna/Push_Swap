/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:46:26 by skanna            #+#    #+#             */
/*   Updated: 2024/03/06 19:08:10 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (!*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_struct(t_struct *structure)
{
	int	i;

	if (structure->head_a != NULL)
		free_stack(&structure->head_a);
	i = 0;
	if (structure->head_b != NULL)
	{
		while (structure->head_b[i])
			free_stack(&structure->head_b[i++]);
		free (structure->head_b);
	}
	free (structure);
}

void	err_handling(t_struct *structure)
{
	free_struct(structure);
	exit (EXIT_FAILURE);
}
