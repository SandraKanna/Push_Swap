/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:41:21 by skanna            #+#    #+#             */
/*   Updated: 2024/02/19 16:32:12 by skanna           ###   ########.fr       */
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
		new_av = malloc (sizeof(char *) * ac);
		if (!new_av)
			return (NULL);
		new_av = ++av;
		*count = ac - 1;
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

int	stack_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	index_sorted(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
