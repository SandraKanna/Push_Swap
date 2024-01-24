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

void	add_to_stack(t_node **stack, int input)
{
	t_node	*new_node;
	t_node	*temp;

	temp = *stack;
	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = input;
	new_node->next = *stack; //linking the new_node to the current stack
	*stack = new_node; //making the new_node the top of the stack == updating the current top
}

void	push(t_node **head, int input)
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

int	pop(t_node **stack)
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

void	print_test(t_node *printme)
{
	while (printme != NULL)
	{
		printf("%i\n", printme->value);
		printme = printme->next;
	}
}

void	print_circ(t_node *print)
{ 
	t_node	*temp = print;

	if (print != NULL) 
	{ 
        printf("%i\n", temp->value); 
        temp = temp->next; 
		while (temp != print)
		{ 
            printf("%i\n", temp->value); 
            temp = temp->next; 
        }
	} 
} 

int main(void)
{
	char *argv[] = {"5", "0", "13", "-67", "553", NULL};
	int		argc = 5;
	int		add = 44;
	t_node	*stack_test;
	t_node	*temp;
	
	//test create stack
	printf("Initial stack:\n---\n");
	stack_test = initialize_stack_a(argv, argc);
//	print_test(stack_test);
	print_circ(stack_test);
	printf("\n");

	//test push
	printf("Add: %i\n---\n", add);
	//add_to_stack(&stack_test, add);
	push(&stack_test, add);
	//print_test(stack_test);
	print_circ(stack_test);
	printf("\n");

	//test pop
	//printf("Remove: %i\n---\n", remove_from_stack(&stack_test));
	printf("Remove: %i\n---\n", pop(&stack_test));
	//print_test(stack_test);
	print_circ(stack_test);
	printf("\n");

	//test swap
	printf("Swap:\n---\n");
	swap(&stack_test);
//	print_test(stack_test);
	print_circ(stack_test);
	printf("\n");
/*
	//test rotate
	printf("Rotate:\n---\n");

	print_test(stack_test);
	printf("\n");*/
	return 0;
}

