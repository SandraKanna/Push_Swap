/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/02/21 16:37:03 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

// void	push_swap(t_node **stack_a)
// {
// 	t_node	*stack_b;
// 	// t_node	*temp;

// 	stack_b = NULL;
// 	// temp = *stack_a;
// 	while (!is_sorted(*stack_a))
// 	{
// 		if ((*stack_a)->value < (*stack_a)->next->value)
// 			ra(stack_a);
// 		else
// 			pb(stack_a, &stack_b);
// 	}
// 	while (stack_b != NULL)
// 		pa(stack_a, &stack_b);
// }

t_node	*initialize_b(t_struct *struct_a)
{
	t_struct	*struct_b;
	t_node		*stack_b;
	int			len;

	len = struct_a->count;

}

void	sort_5(t_struct *struct_a)
{
	initialize_b(struct_a);
}

void	push_swap(t_struct *struct_a)
{
	if (struct_a->list != NULL)
	{
		if ((struct_a->count > 5))
			sort_5();
	}
	

}

int	main(int argc, char **argv)
{
	t_struct	*struct_a;
	int			elements_count;
	char		**list;

	if (argc < 2)
		return (0);
	elements_count = 0;
	list = parse_args(&elements_count, argc, argv);
	if (!list)
		return (0);
	if (check_errors(elements_count, list))
		return (write (2, "Error\n", 6));
	struct_a = initialize_a(list, elements_count);
	if (!struct_a)
		return (free_tab(list), err_handling(struct_a), 0);
	free_tab(list);
	push_swap(struct_a);
	return (free_struct(struct_a), 0);
}
