#include "../Includes/push_swap.h"
#include <stdio.h>

#define COLOR_RED "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_YELLOW "\033[93m"
#define COLOR_RESET "\033[0m"

void	print_stacks(t_node *A, t_node *B)
{
	while (A != NULL && B != NULL)
	{
		printf("\n%i    %i\n", A->value, B->value);
		A = A->next;
		B = B->next;
	}
	while (A != NULL)
	{
		printf("%i\n", A->value);
		A = A->next;
	}
	while (B != NULL)
	{
		printf("     %i\n", B->value);
		B = B->next;
	}
}

int	main(int argc, char **argv)
{
	char	**new_tab = NULL;
	t_node	*stack_b = NULL;
	int		ac;
	// t_node	*stack_a;
	t_struct	*a;

	if (argc >= 2)
	{
		new_tab = parse_args(&ac, argc, argv);
		if (check_errors(ac, new_tab))
			return (write (2, "Input error\n", 12));

		printf(COLOR_YELLOW "\n##### TEST OPS #####\n" COLOR_RESET);
		printf("\nInitializing stacks A and B:\n----------\n");
		a = initialize_a(new_tab, ac);
		print_stacks(a->head, stack_b);
		printf("-    -\n");
		printf("A    B\n");
		printf("\n");

		//test push & pop ops
		printf("Exec ops:\n----------\n");
		pb(&a->head, &stack_b);
		sa(&a->head);
		pb(&a->head, &stack_b);
		ss(&a->head, &stack_b);
		print_stacks(a->head, stack_b);
		printf("-    -\n");
		printf("A    B\n");
		printf("\n");

		sa(&a->head);
		print_stacks(a->head, stack_b);
		printf("-    -\n");
		printf("A    B\n");
		printf("\n");
	}
	
	return (0);
}