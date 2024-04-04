/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/04/04 11:28:19 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_node *list, int rank)
{
	t_node	*temp;
	int		position;

	position = 1;
	temp = list;
	while (temp != NULL)
	{
		if (temp->rank == rank)
			break ;
		position++;
		temp = temp->next;
	}
	return (position);
}

int	get_bit_len(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n >>= 1;
	}
	return (len);
}

int	count_bits(t_node *list, int bit, int i)
{
	t_node	*cur;
	int		bit_cur;
	int		count;

	cur = list;
	count = 0;
	while (cur != NULL)
	{
		bit_cur = (cur->rank >> i) & 1;
		if (bit_cur == bit)
			count++;
		cur = cur->next;
	}
	return (count);
}

int	select_bit(t_node *list, int bit_count, int i)
{
	int		zeros;
	int		ones;
	int		bit_cur;
	t_node	*cur;

	zeros = 0;
	ones = 0;
	cur = list;
	while (cur != NULL)
	{
		bit_cur = cur->rank;
		if (bit_cur & (1 << (bit_count - i)))
			ones++;
		else
			zeros++;
		cur = cur->next;
	}
	if (max_value(zeros, ones) == 1)
		return (1);
	return (0);
}

int	is_column_complete(t_node *list, int bit, int i)
{
	t_node	*cur;
	int		bit_cur;

	cur = list;
	while (cur != NULL)
	{
		bit_cur = (cur->rank >> i) & 1;
		if (bit_cur == bit)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
}
