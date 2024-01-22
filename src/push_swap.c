/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/01/22 18:18:13 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	push_swap(t_node *stack_a)
{
	
}


t_node	*initialize_stack_a(char **av)
{
	t_node	*stack_a;
	int		input;
	int		i;
	int		dummy;

	stack_a = NULL;
	dummy = 0;
	i = 0;
	while (av[i])
	{
		input = do_atoi(av[i], &dummy);
		add_to_stack(&stack_a, input);
		i++;
	}
	return (stack_a);
}


int	main(int argc, char **argv)
{
	int		ac;
	char	**av;
	t_node	*stack_a;

	av = NULL;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		av = check_in_quotes(&ac, argv);
	else
	{
		ac = argc - 1;
		av = argv++;
	}
	if (check_errors(ac, av))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	stack_a = initialize_stack_a(av);
	free_args(av);
	push_swap(&stack_a);
	return (0);
}
