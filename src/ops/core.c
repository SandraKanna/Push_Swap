/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:46:21 by skanna            #+#    #+#             */
/*   Updated: 2024/02/19 15:11:05 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push(t_node **stack, int input, int *err)
{
	t_node	*new_node;

	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
	{
		*err = 1;
		return ;
	}
	new_node->value = input;
	new_node->next = *stack; //linking the new_node to the current stack
	*stack = new_node; //making the new_node the top of the stack == updating the current top
}

int	pop(t_node **stack)
{
	t_node	*top_node;
	int		value;

	if (stack == NULL || *stack == NULL)
		return (0);//cant remove element of empty
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

	if (*stack == NULL || (*stack)->next == NULL) //if empty or only one node
		return ;
	first = *stack; //saving first node
	*stack = (*stack)->next;//detaching first node
	temp = *stack;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = first; //reattaching first node at the end
	first->next = NULL;
}

void	rotate_down(t_node **stack)
{
	t_node	*temp;
	t_node	*new_first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while(temp->next->next != NULL)
		temp = temp->next;
	new_first = temp->next;
	new_first->next = *stack;
	temp->next = NULL;
	*stack = new_first;
}
