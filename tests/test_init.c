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
	char	**new_tab = NULL;
	int		ac;
	int set_len;
	t_struct	*a;

	if (argc >= 2)
	{
		new_tab = parse_args(&ac, argc, argv);
		if (check_errors(ac, new_tab))
			return (write (2, "Input error\n", 12));

		printf(COLOR_YELLOW "\n##### TEST: INITIALIZATION OF STRUCTURE A #####\n" COLOR_RESET);
		a = struct_init(new_tab, ac);
		printf("\nNumber of elements: %i\n", a->count);
		printf("\nInitializing stack A\n----------\n");
		print_test(a->head_a);
		printf("-\n");
		printf("A\n\n");
		printf("\nInitializing working set and tags\n----------\n\n");
		if (a->count > 7)		
			set_len = 7;
		else
			set_len = a->count;
		for (int j = 0; j < set_len; j++)
			printf("set[%i]: %i\n", j, a->set[j]);
		printf("\n");
		for (int j = 0; j < set_len; j++)
			printf("tag[%i]: %i\n", j, a->tags[j]);
		if (a->sorted)
			printf(COLOR_GREEN "\n***** The working set is sorted *****\n\n" COLOR_RESET);
		else
			printf(COLOR_RED "\n----- The working set is NOT sorted -----\n\n" COLOR_RESET);
	
	}
	else
		printf("Please enter at least 2 numbers after './init'\n");
	return (0);
}