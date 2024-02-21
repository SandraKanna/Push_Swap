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

//void	tag_values_b(t_struct *structure, int set_size)

void	tag_values_a(t_struct *structure, int set_size)
{
	int	i;
	int	j;

	structure->tags = malloc (sizeof(int) * set_size);
	if (!structure->tags)
		err_handling(structure);
	i = 0;
	while (i < set_size)
	{
		j = 0;
		while (j < set_size - 1)
		{
			if (structure->set[j] < structure->set[j + 1])
				structure->tags[i] = structure->set[j];
			j++;
		}
		i++;
	}
}

void	get_set(t_struct *structure, int set_size)
{
	t_node	*last;
	t_node	*last_prev;
	t_node	*temp;
	int		i;

	structure->set = malloc (sizeof(int *) * set_size);
	if (!structure->set)
		err_handling(structure);
	i = 0;
	temp = *structure->head;
	while (temp != NULL && i < set_size)
	{
		structure->set[i] = temp->value;
		temp = temp->next;
		i++;
	}
	last = find_last(*structure->head);
	if (last != NULL)
		structure->set[i++] = last->value;
	last_prev = find_prev_last(*structure->head);
	if (last_prev != NULL)
		structure->set[i] = last_prev->value;
	tag_values_a(structure, set_size);
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
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->value = input;
		last = find_last(*stack);
		last->next = new_node;
	}
}

void	list_init(t_struct *stack_a, int input, int *err)
{
	if (stack_a->head != NULL)
	{
		if (input > (*stack_a->head)->value)
			return (push_bottom(stack_a->head, input, err));
	}
	push_top(stack_a->head, input, err);
}

t_struct	*initialize_a(char **av, int count)
{
	t_struct	*struct_a;
	int			input;
	int			i;
	int			err;

	struct_a = malloc (sizeof(t_struct));
	if (!struct_a)
		return (NULL);
	struct_a->count = count;
	struct_a->head = NULL;
	i = 0;
	err = 0;
	while (i < count)
	{
		input = ft_atoi(av[i]);
		printf("test: %i\n", input);
		list_init(struct_a, input, &err);//correct dereferencing error
		printf("test: %p\n", struct_a->head);
		if (err)
			return (NULL);
		i++;
	}
	get_set(struct_a, 7);
	struct_a->sorted = index_sorted(struct_a->set, 7);
	return (struct_a);
}

