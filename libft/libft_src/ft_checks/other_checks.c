/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:37:04 by skanna            #+#    #+#             */
/*   Updated: 2024/03/15 11:13:37 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftv3.h"

int	is_nbr(char *str)
{
	int	i;

	i = 0;
	if (!str || ((str[0] == '-' || str[0] == '+') && str[1] == '\0'))
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

int	is_bigger(int value1, int value2)
{
	if (value1 > value2)
		return (1);
	else
		return (0);
}

int	is_smaller(int value1, int value2)
{
	if (value1 < value2)
		return (1);
	else
		return (0);
}

int	has_quotes(char const *str)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			quotes++;
		i++;
	}
	if (quotes % 2 == 0)
		return (1);
	else if (quotes == 0)
		return (0);
	return (-1);
}
