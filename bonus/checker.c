/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:43:04 by sandra            #+#    #+#             */
/*   Updated: 2024/04/15 23:52:38 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_values(t_node *stack)
{
	if (stack == NULL)
		return ;
	while (stack != NULL)
	{
		ft_printf("%i\n", stack->value);
		stack = stack->next;
	}
}

void	checker(t_struct *structure)
{
	print_values(structure->head_a);
	ft_printf("\n--- Initial list ---\n");
	push_swap(structure, structure->count);
	ft_printf("\n--- Final list ---\n");
	print_values(structure->head_a);
	if (is_stack_sorted(structure->head_a, structure->count))
		ft_printf("OK\n");
	else
		ft_printf("KO");
}

int	main(int argc, char **argv)
{
	t_struct		*structure;
	int				elements_count;
	char			**list;

	if (argc < 2)
		return (0);
	elements_count = 0;
	list = parse_args(&elements_count, argc, argv);
	if (!list || !*list || check_errors(elements_count, list))
	{
		if (argc == 2 && list)
			free_tab(list);
		return (write (2, "Error\n", 6));
	}
	structure = init_struct(list, elements_count);
	if (argc == 2)
		free_tab(list);
	if (!structure)
		return (0);
	checker(structure);
	return (free_struct(structure), 0);
}