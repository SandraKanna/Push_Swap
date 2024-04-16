/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:43:04 by sandra            #+#    #+#             */
/*   Updated: 2024/04/16 17:34:03 by skanna           ###   ########.fr       */
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

void	exec_instructions(t_struct *structure, t_node *instructions)
{
	t_node	*cur;

	cur = instructions;
	while (cur != NULL)
	{
		if (cur->value == 1)
			push_to_stack(structure, 'a');
		else if (cur->value  == 2)
			push_to_stack(structure, 'b');
		else if (cur->value == 3)
			swap_stack(structure, 'a');
		else if (cur->value  == 4)
			swap_stack(structure, 'b');
		else if (cur->value  == 5)
			swap_stack(structure, 'c');
		else if (cur->value  == 6)
			rotate_up_stack(structure, 'a');
		else if (cur->value == 7)
			rotate_up_stack(structure, 'b');
		else if (cur->value  == 8)
			rotate_up_stack(structure, 'c');
		else if (cur->value == 9)
			rotate_down_stack(structure, 'a');
		else if (cur->value  == 10)
			rotate_down_stack(structure, 'b');
		else if (cur->value  == 11)
			rotate_down_stack(structure, 'c');
	}
}

// int	check_instructions(t_node **instructions)
// {
// 	t_node	*cur;

// 	cur = *instructions;
// 	while (cur != NULL)
// 	{
// 		if (ft_strncmp(cur->line, "pa", 1))
// 		{
// 			cur->value = 1;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "pb", 2))
// 		{
// 			cur->value = 2;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "sa", 2))
// 		{
// 			cur->value = 3;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "sb", 2))
// 		{
// 			cur->value = 4;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "ss", 2))
// 		{
// 			cur->value = 5;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "ra", 2))
// 		{
// 			cur->value = 6;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "rb", 2))
// 		{
// 			cur->value = 7;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "rr", 2))
// 		{
// 			cur->value = 8;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "rra", 3))
// 		{
// 			cur->value = 9;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "rrb", 3))
// 		{
// 			cur->value = 10;
// 			cur = cur->next;
// 		}
// 		else if (ft_strncmp(cur->line, "rrr", 3))
// 		{
// 			cur->value = 11;
// 			cur = cur->next;
// 		}
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// void	create_instruction_list(t_node **stack, char *line, int *err)
// {
// 	t_node	*new_node;
// 	t_node	*last;
	
// 	new_node = NULL;
// 	last = NULL;
// 	new_node = malloc (sizeof(t_node));
// 	if (!new_node)
// 	{
// 		*err = 1;
// 		return ;
// 	}
// 	new_node->value = 0;
// 	new_node->rank = 0;
// 	new_node->line = ft_strdup(line);
// 	if (!new_node->line)
// 	{
// 		*err = 1;
// 		return ;
// 	}
// 	// printf("stored line: %s", new_node->line);
// 	new_node->next = NULL;
// 	if (*stack == NULL)
// 		*stack = new_node;
// 	else
// 	{
// 		last = find_last(*stack);
// 		last->next = new_node;
// 	}
// }

int	checker(t_struct *structure)
{
	char	*line;
	t_node	*instructions;
	int		err;
	
	err = 0;
	instructions = NULL;
	while (1)
	{
		line = get_next_line(0);
		printf("line1: %s", line);
		if (line == NULL)
			break;
		// create_instruction_list(&instructions, line, &err);
		// printf("stored line: %s", instructions->line);
		printf("line2: %s", line);
		free (line);
		if (err)
		{
			printf("test err");
			free_stack(&instructions);
			return (err_handling(structure), 1);
		}
	}
	printf("test");
	if (!check_instructions(&instructions))
		return (free_stack(&instructions), 0);
	exec_instructions(structure, instructions);
	free_stack(&instructions);
	return (1);
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
	if (!checker(structure))
		return (write (2, "Error\n", 6));
	if (is_stack_sorted(structure->head_a, structure->count))
		write(1, "OK\n");
	else
		ft_printf("KO\n");
	return (free_struct(structure), 0);
}
