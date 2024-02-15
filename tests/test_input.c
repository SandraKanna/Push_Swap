#include "../Includes/push_swap.h"

void	test_parse_args(int *argc2, char **argv2, char ***new_tab)
{
	int		ac_test;
	int		i = 0;

	printf("initial argc: %i\n", *argc2);
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
		if (!is_signed_nbr(test_argv[i]))
		{
			printf("argv[%i] = %s is not a digit\n", i, test_argv[i]);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	printf("All inputs are digits\n");
}

void	test_convert(int *ac, char **av, int **convert)
{
	int	err = 0;
	int	i = 0;

	while (i < *ac)
	{
		(*convert)[i] = do_atoi(av[i], &err);
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

		printf("---Arguments parsing---\n");
		test_parse_args(&ac, av, &new_tab);
		printf("\n");

		printf("---Checking digits---\n");
		test_digits(ac, new_tab);
		printf("\n");

		printf("---Converting to int---\n");
		convert = malloc (sizeof(int) * (ac));
		if (!convert)
		{
			printf("Malloc error");
			exit(1);
		}
		test_convert(&ac, new_tab, &convert);
		if (has_duplicates(ac, convert))
			printf("There are duplicates in the input\n");
		else
			printf("There are no duplicates in the input\n");
		free(convert);
	}
	else
		printf("Please enter at least 2 numbers after './test1'\n");
}
