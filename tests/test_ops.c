#include "../Includes/push_swap.h"

void	print_stacks(t_node *A, t_node *B)
{
	while (A != NULL && B != NULL)
	{
		printf("%i  %i\n", A->value, B->value);
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
		printf("   %i\n", B->value);
		B = B->next;
	}
}

int	main(int argc, char **argv)
{
	char	**new_tab = NULL;
	t_node	*stack_b = NULL;
	int		ac;
	t_node	*stack_a;

	if (argc >= 2)
	{
		new_tab = parse_args(&ac, argc, argv);
		//create stack
		printf("Initializing stacks A and B:\n----------\n");
		stack_a = initialize_stack_a(new_tab, ac);
		print_stacks(stack_a, stack_b);
		printf("-   -\n");
		printf("A   B\n");
		printf("\n");

		//test push & pop ops
		printf("Exec push ops:\n----------\n");
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		printf("-   -\n");
		printf("A   B\n");
		printf("\n");

		// pa(&stack_a, &stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// sa(&stack_a);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// pb(&stack_a, &stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// sb(&stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// ss(&stack_a, &stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// ra(&stack_a);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// pb(&stack_a, &stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// rb(&stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// rr(&stack_a, &stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// rra(&stack_a);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// rrb(&stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// rrr(&stack_a, &stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("-   -\n");
		// printf("A   B\n");
		// printf("\n");

		// printf("\n");
	}
	else
		printf("Please enter at least 2 numbers after './test4'\n");
	return (0);
}