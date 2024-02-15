#include "../Includes/push_swap.h"

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
	char	**new_tab = NULL;
//	t_node	*stack_b = NULL;
	int		ac;
	t_node	*stack_a;

	new_tab = parse_args(&ac, argc, argv);
	//create stack
	printf("\nInitial stack:\n------\n");
	stack_a = initialize_stack_a(new_tab, ac);
	printf("\n");
	print_test(stack_a);

	//test algo simple
	printf("\noperations:\n-----\n");
	push_swap(&stack_a);
	printf("\nSorted stack:\n-----\n");
	print_test(stack_a);
	printf("\n");

	// printf("\n");
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