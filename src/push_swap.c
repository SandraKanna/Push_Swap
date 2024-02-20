/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/02/19 19:58:37 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	push_swap(t_node **stack_a)
{
	t_node	*stack_b;
	// t_node	*temp;

	stack_b = NULL;
	// temp = *stack_a;
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			ra(stack_a);
		else
			pb(stack_a, &stack_b);
	}
	while (stack_b != NULL)
		pa(stack_a, &stack_b);
}
/*
void	sort_5()
{

}

void	sort_3()
{

}

void	push_swap(t_node **stack, int count)
{
	while (count >= 5)
}

t_node	*initialize_stack_b(char **av, int count)
{
	
}*/

t_struct	*initialize_b(char **av, int count)
{

}

void	fill_index(t_struct *structure)
{
	int		i;
	t_node	*last;
	t_node	*last_prev;
	t_node	*head;

	i = 0;
	head = structure->list;
	last = find_last_value(structure->list);
	last_prev = find_prev_last_value (structure->list);
	while (i < 5)
	{
		if (head != NULL)
		{
			if (head->value > )
		}
	}
}

t_node	*initialize_a(char **av, int count, t_struct *struct_a)
{
	t_node	*stack_a;
	int		input;
	int		i;
	int		err;

	stack_a = NULL;
	i = count - 1;
	err = 0;
	while (i >= 0)
	{
		input = ft_atoi(av[i]);
		push(&stack_a, input, &err);
		if (err)
			err_handling(struct_a);
		i--;
	}
	struct_a->list = stack_a;
	fill_index(struct_a);

	return (struct_a);
}


int	main(int argc, char **argv)
{
	t_struct	*struct_a;
	int			elements_count;
	char		**list;
	t_node		*stack_a;

	if (argc < 2)
		return (0);
	elements_count = 0;
	list = parse_args(&elements_count, argc, argv);
	if (!list)
		return (0);
	if (check_errors(elements_count, list))
		return (write (2, "Error\n", 6));
	struct_a = malloc (sizeof(t_struct));
	if (!struct_a)
		return (err_handling(struct_a), 0);
	stack_a = initialize_a(list, elements_count, &struct_a);
	free_tab(list);
	//push_swap(&stack_a, elements_count);
	free_stack(stack_a);
	return (0);
}
