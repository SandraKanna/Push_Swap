/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:19:29 by skanna            #+#    #+#             */
/*   Updated: 2024/01/24 19:41:01 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push2(t_node **head, int input)
{
	t_node	*new_node;
	t_node	*temp;

	temp = NULL;
	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = input;
	new_node->next = *head;
	if (*head != NULL)
	{
		temp = *head;
		while (temp->next != *head)
			temp = temp->next;
		temp->next = new_node;
	}
	else
		new_node->next = new_node;
	*head = new_node;
}

int	pop2(t_node **stack)
{
	t_node	*head;
	t_node	*last;
	int		value;

	if (stack == NULL || *stack == NULL)
		return (EXIT_FAILURE);
	head = *stack;
	value = head->value;
	if (head == head->next)
		*stack = NULL;
	else
	{
		last = head->next;
		while (last->next != head)
			last = last->next;
		last->next = head->next;
		*stack = head->next;
	}
	free(head);
	return (value);
}

void	swap2(t_node	**stack)
{
	t_node	*temp;
	t_node	*new_first;
	t_node	*last;

	temp = *stack;
	new_first = temp->next;
	temp->next = new_first->next;
	new_first->next = temp;
	last = NULL;
	if (temp->next != *stack)
	{
		last = *stack;
		while (last->next != *stack)
			last = last->next;
		last->next = new_first;
	}
	*stack = new_first;
}

t_node	*initialize_stack_a2(char **av, int ac)
{
	t_node	*stack_a;
	int		input;
	int		i;
	int		dummy;

	stack_a = NULL;
	dummy = 0;
	i = ac - 1;
	while (i >= 0)
	{
		input = do_atoi(av[i], &dummy);
		push2(&stack_a, input);
		i--;
	}
	return (stack_a);
}
/*
void	rotate12(t_node **stack)
{
	t_node	temp1;
	t_node	*temp2;
	
	while(stack != NULL)
	{
		
	}
	
}*/



