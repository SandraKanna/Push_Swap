/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/02/19 14:49:44 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

// void	push_swap(t_node **stack_a)
// {
// 	t_node	*stack_b;
// 	t_node	*temp;

// 	stack_b = NULL;
// 	temp = *stack_a;
// 	while (!is_sorted(*stack_a) && *stack_a != NULL)
// 	{
// 		if ((*stack_a)->value < (*stack_a)->next->value)
// 			sa(stack_a);
// 		else
// 			pb(stack_a, &stack_b);
// 	}
// 	while (stack_b != NULL)
// 		pa(stack_a, &stack_b);
// }



t_node	*initialize_stack_a(char **av, int ac)
{
	t_node	*stack_a;

	int		input;
	int		i;

	stack_a = NULL;
	i = ac - 1;
	while (i >= 0)
	{
		input = ft_atoi(av[i]);
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
	free_tab(av);
	//push_swap(&stack_a, &stack_b);
	//free_stack(stack_a);
	//free_stack(stack_b);
	return (0);
}*/
