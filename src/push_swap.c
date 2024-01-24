/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/01/24 19:41:01 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	push1(t_node **stack, int input)
{
	t_node	*new_node;

	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = input;
	new_node->next = *stack; //linking the new_node to the current stack
	*stack = new_node; //making the new_node the top of the stack == updating the current top
}

int	pop1(t_node **stack)
{
	t_node	*top_node;
	int		value;

	if (stack == NULL || *stack == NULL)
		return (EXIT_FAILURE);
	top_node = *stack;
	value = top_node->value;
	*stack = top_node->next;
	free(top_node);
	return (value);
}

void	swap1(t_node	**stack)
{
	t_node	*temp1;
	t_node	*new_first;

	temp1 = *stack;//temp1 stocks 5 and whole list
	new_first = temp1->next;//temp2 stocks 0 and rest of the list
	temp1->next = new_first->next;//this stocks 5, 13, -67 and 553
	new_first->next = temp1;//this places 0 before 5 and rest of list
	*stack = new_first; //relink to the top of list
}

void	rotate_up(t_node **stack)
{
	t_node	*temp;
	t_node	*first;

	if (*stack == NULL || (*stack)->next == NULL) //if empty of only one node
		return ;
	first = *stack; //saving first node
	*stack = (*stack)->next;//detaching first node
	temp = *stack;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = first; //reattaching first node at the end
	first->next = NULL;
}

/*void	push_swap(t_node **stack_a, t_node	**stack_b)
{
	//push: move the top elem from one stack to the top of the other as long as they're not empty

	//swap: swap the first 2 elemest of the stack, only if it has more than 1 element
	//rotate: Shift up all elements of stack by 1.
	//reverse: Shift down all elements of stack by 1.
}*/

t_node	*initialize_stack_a(char **av, int ac)
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
		push1(&stack_a, input);
		i--;
	}
	return (stack_a);
}
/*
int	main(int argc, char **argv)
{
	int		ac;
	char	**av;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	av = parse_args(&ac, argc, argv);
	if (check_errors(ac, av))
	{
		write (2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	stack_a = initialize_stack_a(av);
	//free_args(av);
	//push_swap(&stack_a, &stack_b);
	//free_stack(stack_a);
	//free_stack(stack_b);
	return (0);
}*/
