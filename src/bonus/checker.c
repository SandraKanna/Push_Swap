/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:43:04 by sandra            #+#    #+#             */
/*   Updated: 2024/04/17 00:53:35 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"

int	checker(t_struct *structure)
{
	char	*line;
	int		check;

	line = get_next_line(0);
	while (line)
	{
		check = check_and_exec(structure, line);
		ft_printf(" count: %i\n", structure->count);
		free (line);
		if (!check)
			return (0);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_struct	*structure;
	int			elements_count;
	char		**list;
	int			is_sorted;

	if (argc < 2)
		return (0);
	is_sorted = 0;
	elements_count = 0;
	list = check_input(&elements_count, argc, argv);
	if (!list)
		return (0);
	structure = init_struct(list, elements_count);
	if (argc == 2)
		free_tab(list);
	if (!structure)
		return (0);
	if (!checker(structure))
		return (write (2, "Error\n", 6));
	is_sorted = is_stack_sorted(structure->a, structure->count);
	if (is_sorted == 1 && structure->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_struct(structure), 0);
}
