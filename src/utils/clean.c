/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:46:26 by skanna            #+#    #+#             */
/*   Updated: 2024/02/27 16:59:24 by skanna           ###   ########.fr       */
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
	if (structure->set != NULL)
		free (structure->set);
	if (structure->tags != NULL)
		free (structure->tags);
	if (structure->head != NULL)
		free_stack(&structure->head);
	free (structure);
}

void	free_struct_b(t_struct **b)
{
	int	i;

	i = 0;
	while (b[i] != NULL)
		free_struct(b[i++]);
	free (b);
}

void	err_handling_b(t_struct **structure_b, t_struct *structure_a)
{
	free_struct_b(structure_b);
	err_handling(structure_a);
}

void	err_handling(t_struct *structure_a)
{
	if (structure_a != NULL)
		free_struct(structure_a);
	exit (EXIT_FAILURE);
}
