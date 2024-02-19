#include "../Includes/push_swap.h"

#define COLOR_RED "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_YELLOW "\033[93m"
#define COLOR_RESET "\033[0m"

void	print_test(t_node *printme)
{
	while (printme != NULL)
	{
		printf("%i\n", printme->value);
		printme = printme->next;
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		char	**new_tab = NULL;
	//	t_node	*stack_b = NULL;
		int		ac;
		t_node	*stack_a;

		new_tab = parse_args(&ac, argc, argv);
		//create stack
		printf(COLOR_YELLOW "\nInitial stack:\n------\n" COLOR_RESET);
		stack_a = initialize_stack_a(new_tab, ac);
		printf("\n");
		print_test(stack_a);

		//test algo simple
		printf(COLOR_YELLOW "\noperations:\n-----\n" COLOR_RESET);
		push_swap(&stack_a);
		printf(COLOR_YELLOW "\nSorted stack:\n-----\n" COLOR_RESET);
		print_test(stack_a);
		printf("\n");

	}
	else
		printf(COLOR_YELLOW "\nPlease enter at least 2 numbers after './test5'\n\n" COLOR_RESET);

	return (0);
}


/*
The grade depends on how efficient the program's sorting process is.

Sorting 3 values: no more than 3 actions.
Sorting 5 values: no more than 12 actions.
Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
5 points for less than 700 actions
4 points for less than 900
3 points for less than 1100
2 points for less than 1300
1 point for less than 1500
Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
5 points for less than 5500 actions
4 points for less than 7000
3 points for less than 8500
2 points for less than 10000
1 point for less than 11500
*/