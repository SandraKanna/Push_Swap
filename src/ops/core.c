/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:46:21 by skanna            #+#    #+#             */
/*   Updated: 2024/03/13 16:12:10 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push(t_node **stack, int input, int rank, int *err)
{
	t_node	*new_node;

	new_node = NULL;
	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
	{
		*err = 1;
		return ;
	}
	new_node->value = input;
	new_node->rank = rank;
	new_node->last = NULL;
	new_node->next = *stack;
	*stack = new_node;
}

int	pop(t_node **stack)
{
	t_node	*top_node;
	int		value;

	if (stack == NULL || *stack == NULL)
		return (0);
	top_node = *stack;
	value = top_node->value;
	*stack = top_node->next;
	free(top_node);
	return (value);
}

void	swap(t_node	**stack)
{
	t_node	*temp1;
	t_node	*new_first;

	temp1 = *stack;
	new_first = temp1->next;
	temp1->next = new_first->next;
	new_first->next = temp1;
	*stack = new_first;
}

void	rotate_up(t_node **stack)
{
	t_node	*temp;
	t_node	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}

void	rotate_down(t_node **stack)
{
	t_node	*temp;
	t_node	*new_first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	new_first = temp->next;
	new_first->next = *stack;
	temp->next = NULL;
	*stack = new_first;
}
