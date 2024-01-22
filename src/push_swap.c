/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/01/22 18:18:13 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	push_swap(int	stack_a)
{
	
}

int main (int argc, char **argv)
{
	int		i;
	int		*ac;
	char	**av;

	ac = argc;
	av = NULL;
	if (argc < 2) //no parameters
		return (0);
	if (argc == 2)
		av = check_in_quotes(ac, argv);
	else
	{
		av = malloc (ac * sizeof(char *));
		if (!av)
			return (0);
		ac--;
	}

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
	return (0);
}

/*
av[0] = out
av[1] = 0
av[2] = 5
av[3] = 96
av[4] = 96
ac = 5
*/
 
