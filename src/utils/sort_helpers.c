/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/28 16:43:14 by skanna           ###   ########.fr       */
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

int	count_bits(t_node *list, int bit, int i, int size)
{
	t_node	*cur;
	int		bit_cur;
	int		count;
	int		it;

	cur = list;
	count = 0;
	it = 0;
	while (cur != NULL && it < size)
	{
		bit_cur = (cur->rank >> i) & 1;
		if (bit_cur == bit)
			count++;
		it++;
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

int	is_column_complete(t_node *list, int bit, int i, int n)
{
	t_node	*cur;
	int		bit_cur;
	int		counter;

	cur = list;
	counter = 0;
	while (cur != NULL && counter < n)
	{
		bit_cur = (cur->rank >> i) & 1;
		if (bit_cur == bit)
		{
			cur = cur->next;
			counter++;
		}
		else
			return (0);
	}
	return (1);
}

// int	find_group(int count, int rank)
// {
// 	int	group_size;
// 	int	groups;
// 	int	i;

// 	groups = 1;
// 	i = 3;
// 	while (i <= count && groups <= 11)
// 	{
// 		if (count > i)
// 			groups++;
// 		else
// 			break ;
// 		i += 3;
// 	}
// 	group_size = count / groups;
// 	i = 1;
// 	while (i <= groups)
// 	{
// 		if (rank <= group_size * i)
// 			return (i);
// 		i++;
// 	}
// 	return (groups);
// }



// int	rotate_direction(int size, int pos1, int pos2)
// {
// 	int	mid;
// 	int	rot_dir;

// 	mid = size / 2;
// 	rot_dir = -1;
// 	if (pos1 <= mid)
// 	{
// 		if (pos2 < mid || pos1 < (size - pos2))
// 			rot_dir = 1; //ra
// 		else if (pos1 > (size - pos2))
// 			rot_dir = 2; //rra
// 	}
// 	else if (pos1 > mid)
// 	{
// 		if (pos2 >= mid || pos2 > (size - pos1))
// 			rot_dir = 2; //rra
// 		else if (pos2 < (size - pos1))
// 			rot_dir = 1; //ra
// 	}
// 	return (rot_dir);
// }
