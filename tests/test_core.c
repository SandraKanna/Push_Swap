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
	int		ac;
	int		add = 44;
	t_node	*stack_test;
	t_struct	*a;

	if (argc >= 2)
	{
		new_tab = parse_args(&ac, argc, argv);
		//test create stack
		printf("Initializing the stack A:\n---\n");
		a = initialize_a(new_tab, ac);
		print_test(*a->head = stack_test);
		printf("\n");

		//test push
		printf("Add: %i\n---\n", add);
		push(&stack_test, add);
		print_test(stack_test);
		printf("\n");

		//test pop
		printf("Remove: %i\n---\n", pop(&stack_test));
		print_test(stack_test);
		printf("\n");

		//test swap
		printf("Swap:\n---\n");
		swap(&stack_test);
		print_test(stack_test);
		printf("\n");

		//test rotate up
		printf("Rotate 1 up:\n---\n");
		rotate_up(&stack_test);
		print_test(stack_test);
		printf("\n");
		
		//test rotate down
		printf("Rotate 1 down:\n---\n");
		rotate_down(&stack_test);
		print_test(stack_test);
	}
	else
		printf("Please enter at least 2 numbers after './core'\n");
	
	return (0);
}