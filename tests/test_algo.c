#include "../src/push_swap.h"

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
	push_swap(&stack_a, ac);
	printf("\nSorted stack:\n-----\n");
	print_test(stack_a);
	printf("\n");

	// printf("\n");
	return (0);
}