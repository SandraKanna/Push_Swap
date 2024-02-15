/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/02/15 19:00:42 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_node **stack_a)
{
	t_node	*stack_b;
	t_node	*temp;

	stack_b = NULL;
	temp = *stack_a;
	while (!is_sorted(*stack_a) && *stack_a != NULL)
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			sa(stack_a);
		else
		{
			pb(stack_a, &stack_b);
		//	write(2, "test pb\n", 8);
		}
	}
	//write(2, "test2\n", 6);
	while (stack_b != NULL)
		pa(stack_a, &stack_b);
}

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
		push(&stack_a, input);
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
