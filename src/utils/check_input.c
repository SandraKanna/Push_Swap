/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:41:21 by skanna            #+#    #+#             */
/*   Updated: 2024/04/17 00:18:25 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/push_swap.h"
#include "push_swap.h"

int	has_duplicates(int ac, int *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(int int_count, char **int_list)
{
	int	i;
	int	*temp_conversion;
	int	error;

	i = 0;

	temp_conversion = malloc (sizeof(int *) * int_count);
	if (!temp_conversion)
		return (1);
	while (i < int_count)
	{
		if (!is_nbr(int_list[i]))
			return (free (temp_conversion), 1);
		error = 0;
		temp_conversion[i] = ft_atoi_err(int_list[i], &error);
		if (error)
			return (free (temp_conversion), 1);
		i++;
	}
	if (has_duplicates(int_count, temp_conversion))
		return (free (temp_conversion), 1);
	return (free (temp_conversion), 0);
}

char	**parse_args(int *count, int ac, char **av)
{
	char	**new_av;
	int		i;

	if (ac == 2)
	{
		new_av = ft_split(av[1], ' ');
		if (!new_av)
			return (NULL);
		i = 0;
		while (new_av[i] != NULL)
			i++;
		*count = i;
	}
	else
	{
		new_av = ++av;
		*count = ac - 1;
	}
	return (new_av);
}

char	**check_input(int *elements_count, int argc, char **argv)
{
	char	**list;

	list = parse_args(elements_count, argc, argv);
	if (!list || !*list)
	{
		if (argc == 2 && list)
			free_tab(list);
		write (2, "Error\n", 6);
		return (NULL);
	}
	if (check_errors(*elements_count, list))
	{
		if (argc == 2 && list)
			free_tab(list);
		write (2, "Error\n", 6);
		return (NULL);
	}
	return (list);
}
