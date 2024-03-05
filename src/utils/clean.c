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

void	free_b(t_node ***b)
{
	int	i;

	i = 0;
	while (b[i] != NULL)
		free_stack(b[i++]);
}

void	free_struct(t_struct *structure)
{
	if (structure->head_a != NULL)
		free_stack(&structure->head_a);
	if (structure->head_b != NULL)
		free_b(&structure->head_b);
	free (structure);
}

void	err_handling(t_struct *structure)
{
	free_struct(structure);
	exit (EXIT_FAILURE);
}
