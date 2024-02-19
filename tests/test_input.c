#include "../Includes/push_swap.h"
# include <stdio.h>

#define COLOR_RED "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_YELLOW "\033[93m"
#define COLOR_RESET "\033[0m"

void	test_parse_args(int *argc2, char **argv2, char ***new_tab)
{
	int		ac_test;
	int		i = 0;

	printf("\ninitial argc: %i\n", *argc2);
	while (argv2[i])
	{
		printf("arg[%i}: %s\n", i, argv2[i]);
		i++;
	}
	i = 0;
	*new_tab = parse_args(&ac_test, *argc2, argv2);
	*argc2 = ac_test;
	printf("new argc: %i\n", *argc2);
	while ((*new_tab)[i])
	{
		printf("new arg[%i}: %s\n", i, (*new_tab)[i]);
		i++;
	}
}

void	test_digits(int test_argc, char **test_argv)
{
	int	i = 0;

	while (i < test_argc)
	{
		if (!is_nbr(test_argv[i]))
		{
			printf(COLOR_RED "argv[%i] = %s is not a digit\n" COLOR_RESET, i, test_argv[i]);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	printf(COLOR_GREEN "\n---All inputs are digits---\n" COLOR_RESET);
}

void	test_convert(int *ac, char **av, int **convert)
{
	int	err = 0;
	int	i = 0;

	while (i < *ac)
	{
		(*convert)[i] = ft_atoi_err(av[i], &err);
		printf("%s was converted to int %i\n", av[i], (*convert)[i]);
		i++;
	}
}


int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		int		*convert;
		char	**new_tab = NULL;

		printf(COLOR_YELLOW "\n---Arguments parsing---\n" COLOR_RESET);
		test_parse_args(&ac, av, &new_tab);
		printf("\n");

		printf(COLOR_YELLOW "\n---Checking digits---\n" COLOR_RESET);
		test_digits(ac, new_tab);
		printf("\n");

		printf(COLOR_YELLOW "\n---Converting to int---\n" COLOR_RESET);
		convert = malloc (sizeof(int) * (ac));
		if (!convert)
		{
			printf(COLOR_RED "\nMalloc error\n" COLOR_RESET);
			exit(1);
		}
		test_convert(&ac, new_tab, &convert);
		if (has_duplicates(ac, convert))
			printf(COLOR_RED "\n---There are duplicates in the input---\n\n" COLOR_RESET);
		else
			printf(COLOR_GREEN "\n---There are no duplicates in the input---\n\n" COLOR_RESET);
		free(convert);
	}
	else
		printf(COLOR_YELLOW "\nPlease enter at least 2 numbers after './test1'\n\n" COLOR_RESET);
}
