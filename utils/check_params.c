/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:41:21 by skanna            #+#    #+#             */
/*   Updated: 2024/01/23 17:29:53 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str || ((str[0] == '-' || str[0] == '+') && str[1] == '\0'))
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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

int	check_errors(int ac, char **av)
{
	int	i;
	int	error;
	int	*int_convert;

	i = 0;
	int_convert = malloc (sizeof(int *) * ac);
	if (!int_convert)
		return (1);
	while (i < ac)
	{
		if (!ft_isdigit(av[i]))
		{
			free (int_convert);
			return (1);
		}
		error = 0;
		int_convert[i] = do_atoi(av[i], &error);
		if (error)
			return (1);
		i++;
	}
	if (has_duplicates(ac, int_convert))
		return (1);
	return (0);
}
