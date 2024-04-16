/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:43:04 by sandra            #+#    #+#             */
/*   Updated: 2024/04/16 23:23:23 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"

int	check_push(t_struct *structure, char *instruction)
{
	int	err;

	err = 0;
	if (ft_strncmp(instruction, "pa\n", 3) == 0)
	{
		pa(&structure->a, &structure->b, &err);
		if (err)
			return (err_handling(structure), 0);
		else
			return (1);
	}
	if (ft_strncmp(instruction, "pb\n", 3) == 0)
	{
		pb(&structure->a, &structure->b, &err);
		if (err)
			return (err_handling(structure), 0);
		else
			return (1);
	}
	return (0);
}

int	check_rot(t_struct *structure, char *instruction)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		return (rotate_up(&structure->a), 1);
	if (ft_strncmp(instruction, "rb\n", 3) == 0)
		return (rotate_up(&structure->b), 1);
	if (ft_strncmp(instruction, "rr\n", 3) == 0)
	{
		rotate_up(&structure->a);
		rotate_up(&structure->b);
		return (1);
	}
	return (0);
}

int	check_swap(t_struct *structure, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		return (swap(&structure->a), 1);
	if (ft_strncmp(instruction, "sb\n", 3) == 0)
		return (swap(&structure->b), 1);
	if (ft_strncmp(instruction, "ss\n", 3) == 0)
	{
		if (structure->b == NULL || structure->b->next == NULL
			|| structure->a == NULL || structure->a->next == NULL)
			return (0);
		swap(&structure->a);
		swap(&structure->b);
		return (1);
	}
	return (0);
}

int	check_and_exec(t_struct *structure, char *instruction)
{
	if (!instruction)
		return (0);
	if (check_push(structure, instruction))
		return (1);
	if (check_rot(structure, instruction))
		return (1);
	if (check_swap(structure, instruction))
		return (1);
	if (ft_strncmp(instruction, "rra\n", 4) == 0)
		return (rotate_down(&structure->a), 1);
	if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		return (rotate_down(&structure->b), 1);
	if (ft_strncmp(instruction, "rrr\n", 4) == 0)
	{
		rotate_down(&structure->a);
		rotate_down(&structure->b);
		return (1);
	}
	return (0);
}

int	checker(t_struct *structure)
{
	char	*line;
	int		check;

	line = get_next_line(0);
	while (line)
	{
		check = check_and_exec(structure, line);
		free (line);
		if (!check)
			return (0);
		line = get_next_line(0);
	}
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
	if (is_stack_sorted(structure->a, structure->count))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_struct(structure), 0);
}
