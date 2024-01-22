/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:41:21 by skanna            #+#    #+#             */
/*   Updated: 2024/01/22 18:12:37 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str || (str[0] == '-' || str[0] == '+') && str[1] != '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	//	printf("test is digit");
	return (1);
}

int	do_atoi(const char *str, int *error)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	//	printf("test atoi: %i\n", num);
	return ((int)(num * sign));
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i]) && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	has_duplicates(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	//printf("test no duplicates: %s\n", av[i]);
	return (0);
}

int	check_errors(int ac, char **av)
{
	int	i;
	int	error;

	i = 0;
	while (i < ac)
	{
		if (!ft_isdigit(av[i]))
			return (1);
		error = 0;
		do_atoi(av[i], &error);
		if (error)
			return (1);
		i++;
	}
	if (has_duplicates(av, ac))
		return (1);
	return (0);
}
