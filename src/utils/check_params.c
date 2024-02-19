/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:41:21 by skanna            #+#    #+#             */
/*   Updated: 2024/02/19 15:03:15 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

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

char	**parse_args(int *ac, int argc, char **av)
{
	char	**new_av;
	int		i;

	if (argc == 2)
	{
		new_av = ft_split(av[1], ' ');
		if (!new_av)
			exit(EXIT_FAILURE);
		i = 0;
		while (new_av[i] != NULL)
			i++;
		*ac = i;
	}
	else
	{
		new_av = malloc (sizeof(char *) * argc);
		if (!new_av)
			exit(EXIT_FAILURE);
		new_av = ++av;
		*ac = argc - 1;
	}
	return (new_av);
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
