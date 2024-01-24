#include "../src/push_swap.h"

void	print_circ(t_node *print)
{ 
	t_node	*temp = print;

	if (print != NULL) 
	{ 
        printf("%i\n", temp->value); 
        temp = temp->next; 
		while (temp != print)
		{ 
            printf("%i\n", temp->value); 
            temp = temp->next; 
        }
	} 
} 

int main(int argc, char **argv)
{
	//char *argv[] = {"5", "0", "13", "-67", "553", NULL};
	//int		argc = 5;
	char	**new_tab = NULL;
	int		ac;
	int		add = 42;
	t_node	*stack_test;

	new_tab = parse_args(&ac, argc, argv);
	//test create stack
	printf("Initializing the stack A:\n---\n");
	stack_test = initialize_stack_a2(new_tab, ac);
	print_circ(stack_test);
	printf("\n");

	//test push
	printf("Adding: %i to the stack\n---\n", add);
	push2(&stack_test, add);
	print_circ(stack_test);
	printf("\n");

	//test pop
	printf("Removing element: %i\n---\n", pop2(&stack_test));
	print_circ(stack_test);
	printf("\n");

	//test swap
	printf("Swap:\n---\n");
	swap2(&stack_test);
	print_circ(stack_test);
	printf("\n");
/*
	//test rotate
	printf("Rotate:\n---\n");

	print_test(stack_test);
	printf("\n");*/
	return 0;
}