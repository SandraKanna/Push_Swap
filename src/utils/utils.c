/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/02/19 19:57:10 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

// int find_biggest(t_node *list)
// {

// }

// int find_smallest(t_node *list)
// {

// }

void	err_handling()
{
	// free_tab();
	// free_list();
	//exit (EXIT_FAILURE);

}

int find_last_value(t_node *list)
{
	t_node	*last;

	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last->value);
}

int	find_prev_last_value(t_node *list)
{
	t_node	*prev;

	prev = list;
	while (prev->next->next != NULL)
		prev = prev->next;
	return (prev->value);
}

int	find_middle_value(t_node *list)
{
	t_node	*middle;
	t_node	*move;

	middle = list;
	move = list->next;
	while (move != NULL && move->next != NULL)
	{
		middle = middle->next;
		move = move->next;
	}
	return (middle->value);
}
