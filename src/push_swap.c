/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/01/25 15:58:29 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
