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

#include "push_swap.h"

void	check_in_quotes(int *ac,  char ** av)
{
	av = ft_split(av[1], ' ');
	if (av == NULL)
		exit();
	&ac = ft_strlen(av[1]);
	//	printf("test ac =2: %i\n", ac);
}

int	ft_isdigit(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

}
	i = 1;
	while (av[i])
	{
		if (!ft_isdigit(av[i])) // not digits
			return (write(1, "Error\n", 6));
		printf("test is_digit: %s\n", av[i]);
		i++;
	}
	i = 1;
	/*while (av[i] && (ac - i) > 0) // duplicates
	{
		if (!ft_strcmp(av[i], av[ac - i]))
			return (write(1, "Error\n", 6));
		printf("test no duplicates: %s\n", av[i]);
		i++;
	}*/
	//int limits

