/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:19:29 by skanna            #+#    #+#             */
/*   Updated: 2024/01/23 11:29:11 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_node **stack, int input)
{
	t_node	*new_node;

	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = input;
	new_node->next = *stack; //linking the new_node to the current stack
	*stack = new_node; //making the new_node the top of the stack == updating the current top
}

int	remove_from_stack(t_node **stack)
{
	t_node	*top_node;
	int		value;

	if (stack == NULL || *stack == NULL)
		return (INT_MIN); //INT_MIN en attendand de trouver message erreur adapte
	top_node = *stack;
	value = top_node->value;
	*stack = top_node->next;
	free(top_node);
	return (value);
}