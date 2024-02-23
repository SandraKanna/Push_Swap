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
	t_struct	*a;

	if (argc >= 2)
	{
		new_tab = parse_args(&ac, argc, argv);
		if (check_errors(ac, new_tab))
			return (write (2, "Input error\n", 12));

		printf("\n##### TEST CORE #####\n");
		printf("Initializing the stack A:\n---\n");
		a = struct_init(new_tab, ac);
		print_test(a->head_a);
		printf("\n");

		//test push
		printf("Add: %i\n---\n", add);
		push(&a->head_a, add, 0);
		print_test(a->head_a);
		printf("\n");

		//test pop
		printf("Remove: %i\n---\n", pop(&a->head_a));
		print_test(a->head_a);
		printf("\n");

		//test swap
		printf("Swap:\n---\n");
		swap(&a->head_a);
		print_test(a->head_a);
		printf("\n");

		//test rotate up
		printf("Rotate 1 up:\n---\n");
		rotate_up(&a->head_a);
		print_test(a->head_a);
		printf("\n");
		
		//test rotate down
		printf("Rotate 1 down:\n---\n");
		rotate_down(&a->head_a);
		print_test(a->head_a);
	}
	else
		printf("Please enter at least 2 numbers after './core'\n");
	
	return (0);
}