/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:41:19 by skanna            #+#    #+#             */
/*   Updated: 2024/02/21 18:34:29 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	put_index(t_struct *structure, int n)
{
	t_node	*last;
	t_node	*last_prev;
	t_node	*temp;
	int		i;

	structure->index = malloc (sizeof(int *) * n);
	if (!structure->index)
		err_handling(structure);
	i = 0;
	temp = structure->head;
	last = find_last(structure->head);
	last_prev = find_prev_last(structure->head);
	while (temp != NULL && i < n)
	{
		structure->index[i] = temp->value;
		temp = temp->next;
		i++;
	}
	if (last != NULL)
		structure->index[i++] = last->value;
	if (last_prev != NULL)
		structure->index[i] = last_prev->value;
}

static void	push_bottom(t_node **stack, int input, int *err)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc (sizeof(t_node));
	if (new_node == NULL)
	{
		*err = 1;
		return ;
	}
	new_node->value = input;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		last = find_last(*stack);
		last->next = new_node;
	}
}

void	list_init(t_node **stack_a, int input, int *err)
{
	t_node	*last;

	if (stack_a != NULL)
	{
		if (is_smaller(input, (*stack_a)->value)) //put smallest at the top of A so head_index = a
			push_top(stack_a, input, err);

	}
	push_bottom(stack_a, input, &err);
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

