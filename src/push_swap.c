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
/*
void	sort_5()
{

}
t_node	*initialize_stack_b(char **av, int count)
{
	
}
*/

void	push_swap(t_struct *structure)
{
	while (structure)
}

int	put_index(t_struct *structure)
{
	t_node	*last;
	t_node	*last_prev;
	t_node	*temp;
	int		i;

	i = 0;
//	head = structure->list;
	last = find_last(structure->list);
	last_prev = find_prev_last(structure->list);
	while (i < 5)
	{
		temp =  structure->list;
		//is a in the right position?
		if (is_smaller(temp->value, temp->next->value))
			structure->index[i] = temp->value;
		if (is_smaller(temp->value, last->value))
			structure->index[i] = last->value;
		else
			structure->index[i] = last->value;
	}
}

t_struct	*initialize_a(char **av, int count)
{
	t_struct	*struct_a;
	t_node		*stack_a;
	int			input;
	int			i;
	int			err;

	stack_a = NULL;
	struct_a = malloc (sizeof(t_struct));
	if (!struct_a)
		return (NULL);
	struct_a->count = count;
	i = count - 1;
	err = 0;
	while (i >= 0)
	{
		input = ft_atoi(av[i]);
		list_init(struct_a->list, input, &err);
		if (err)
			return (NULL);
		i--;
	}
	struct_a->head_index = put_index(struct_a);
	return (struct_a);
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
