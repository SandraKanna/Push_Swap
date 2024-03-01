#include "../Includes/push_swap.h"

#define COLOR_RED "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_YELLOW "\033[93m"
#define COLOR_RESET "\033[0m"

void	print_values(t_node *printme)
{
	while (printme != NULL)
	{
		printf("%i\n", printme->value);
		printme = printme->next;
	}
}

void	print_order(t_node *printme)
{
	if (printme != NULL)
	{
		printf("Head rank: %i and value: %i\n", printme->rank, printme->value);		
		printf("Next rank: %i and value: %i\n", printme->next->rank, printme->next->value);
		printf("Mid rank: %i and value: %i\n", printme->middle->rank, printme->middle->value);
		printf("prev_to_last rank: %i and value: %i\n", printme->prev_to_last->rank, printme->prev_to_last->value);
		printf("Last rank: %i and value: %i\n", printme->last->rank, printme->last->value);
	}
}

int	main(int argc, char **argv)
{
	char		**new_tab = NULL;
	int			ac;
	t_struct	*a;

	if (argc >= 2)
	{
		new_tab = parse_args(&ac, argc, argv);
		if (check_errors(ac, new_tab))
			return (write (2, "Input error\n", 12));

		printf(COLOR_YELLOW "\n##### INITIALIZING STRUCTURE A #####\n" COLOR_RESET);
		a = init_struct(new_tab, ac);
		printf("\nNumber of elements: %i\n", a->count);
		printf(COLOR_YELLOW "\nInitializing stack A\n------------\n" COLOR_RESET);
		print_values(a->head_a);
		printf("\n");
		update_rank(a->head_a, ac);
		update_order(a, 'a');
		print_order(a->head_a);
		printf("\n");
	}
	else
		printf(COLOR_YELLOW "\nPlease enter at least 2 numbers after './core'\n\n" COLOR_RESET);
	return (0);
}

/*
		new_tab = parse_args(&ac, argc, argv);
		if (check_errors(ac, new_tab))
			return (write (2, "Input error\n", 12));

		printf("\n##### TEST CORE #####\n");
		printf("Initializing the stack A:\n---\n");
		a = init_struct(new_tab, ac);
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
*/