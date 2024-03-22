/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:55 by skanna            #+#    #+#             */
/*   Updated: 2024/03/19 11:53:19 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_node *list, int value)
{
	t_node	*temp;
	int		position;

	position = 1;
	temp = list;
	while (temp != NULL)
	{
		if (temp->value == value)
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
