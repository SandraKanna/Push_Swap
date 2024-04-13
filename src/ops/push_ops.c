/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:06:48 by skanna            #+#    #+#             */
/*   Updated: 2024/03/15 10:45:08 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

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

void	pa(t_node **stack_a, t_node **stack_b, int *err)
{
	int	rank;
	int	value;

	if ((*stack_b == NULL) | (stack_b == NULL))
		return ;
	rank = (*stack_b)->rank;
	value = pop(stack_b);
	push(stack_a, value, rank, err);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b, int *err)
{
	int	rank;
	int	value;

	if ((*stack_a == NULL) | (stack_a == NULL))
		return ;
	rank = (*stack_a)->rank;
	value = pop(stack_a);
	push(stack_b, value, rank, err);
	write(1, "pb\n", 3);
	return ;
}

void	push_to_stack(t_struct *structure, char c)
{
	int	err;

	err = 0;
	if (c == 'a')
		pa(&structure->head_a, &structure->head_b, &err);
	else if (c == 'b')
		pb(&structure->head_a, &structure->head_b, &err);
	if (err)
		err_handling(structure);
}
