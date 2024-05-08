/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:51:26 by sandra            #+#    #+#             */
/*   Updated: 2024/04/17 12:10:31 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

// static void	print_stacks(t_node *a, t_node *b)
// {
// 	while (a != NULL && b != NULL)
// 	{
// 		ft_printf("%i		%i\n", a->value, b->value);
// 		a = a->next;
// 		b = b->next;
// 	}
// 	while (a != NULL)
// 	{
// 		ft_printf("%i\n", a->value);
// 		a = a->next;
// 	}
// 	while (b != NULL)
// 	{
// 		ft_printf("     %i\n", b->value);
// 		b = b->next;
// 	}
// 	ft_printf("---		---\n");
// 	ft_printf(" A	 	 B\n\n");
// 	print_stacks(structure->a, structure->b);
// }

static int	check_push(t_struct *structure, char *instruction)
{
	int	err;

	err = 0;
	if (ft_strncmp(instruction, "pa\n", 3) == 0)
	{
		pa(&structure->a, &structure->b, &err);
		if (err)
			return (err_handling(structure), 0);
		else
		{
			return (1);
		}
	}
	if (ft_strncmp(instruction, "pb\n", 3) == 0)
	{
		pb(&structure->a, &structure->b, &err);
		if (err)
			return (err_handling(structure), 0);
		else
		{
			return (1);
		}
	}
	return (0);
}

static int	check_rot(t_struct *structure, char *instruction)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
	{
		rotate_up(&structure->a);
		return (1);
	}
	if (ft_strncmp(instruction, "rb\n", 3) == 0)
	{
		rotate_up(&structure->b);
		return (1);
	}
	if (ft_strncmp(instruction, "rr\n", 3) == 0)
	{
		if (structure->a == NULL || structure->b == NULL)
			return (1);
		rotate_up(&structure->a);
		rotate_up(&structure->b);
		return (1);
	}
	return (0);
}

static int	check_swap(t_struct *structure, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
	{
		if (structure->a == NULL || structure->a->next == NULL)
			return (1);
		swap(&structure->a);
		return (1);
	}
	if (ft_strncmp(instruction, "sb\n", 3) == 0)
	{
		if (structure->b == NULL || structure->b->next == NULL)
			return (1);
		swap(&structure->b);
		return (1);
	}
	if (ft_strncmp(instruction, "ss\n", 3) == 0)
	{
		if (structure->b == NULL || structure->b->next == NULL
			|| structure->a == NULL || structure->a->next == NULL)
			return (1);
		swap(&structure->a);
		swap(&structure->b);
		return (1);
	}
	return (0);
}

int	check_and_exec(t_struct *structure, char *instruction)
{
	if (check_push(structure, instruction))
		return (1);
	if (check_rot(structure, instruction))
		return (1);
	if (check_swap(structure, instruction))
		return (1);
	if (ft_strncmp(instruction, "rra\n", 4) == 0)
	{
		rotate_down(&structure->a);
		return (1);
	}
	if (ft_strncmp(instruction, "rrb\n", 4) == 0)
	{
		rotate_down(&structure->b);
		return (1);
	}
	if (ft_strncmp(instruction, "rrr\n", 4) == 0)
	{
		if (structure->a == NULL || structure->b == NULL)
			return (1);
		rotate_down(&structure->a);
		rotate_down(&structure->b);
		return (1);
	}
	return (0);
}
