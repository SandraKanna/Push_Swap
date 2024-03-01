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

int	main(int argc, char **argv)
{
	char	**new_tab = NULL;
	int		ac;
	// int set_len;
	t_struct	*a;

	if (argc >= 2)
	{
		new_tab = parse_args(&ac, argc, argv);
		if (check_errors(ac, new_tab))
			return (write (2, "Input error\n", 12));

		printf(COLOR_YELLOW "\n##### TEST: INITIALIZATION OF STRUCTURE A #####\n" COLOR_RESET);
		a = init_struct(new_tab, ac);
		printf("\nNumber of elements: %i\n", a->count);
		printf(COLOR_YELLOW "\nInitializing stack A\n----------\n" COLOR_RESET);
		print_values(a->head_a);
		printf("-\n");
		printf("A\n\n");
		if (is_stack_sorted(a->head_a))
			printf("\xE2\x9C\x93 This stack is sorted.\n"); // ✓ This stack is sorted.
		else
			printf("\xE2\x9D\x8C This stack is NOT sorted.\n\n"); // ✗ This stack is NOT sorted.
	}
	else
		printf(COLOR_YELLOW "\nPlease enter at least 2 numbers after './init'\n\n" COLOR_RESET);
	return (0);
}

