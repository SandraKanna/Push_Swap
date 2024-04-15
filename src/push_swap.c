/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandra <sandra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:15:10 by skanna            #+#    #+#             */
/*   Updated: 2024/04/15 23:42:00 by sandra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct		*structure;
	int				elements_count;
	char			**list;

	if (argc < 2)
		return (0);
	elements_count = 0;
	list = parse_args(&elements_count, argc, argv);
	if (!list || !*list || check_errors(elements_count, list))
	{
		if (argc == 2 && list)
			free_tab(list);
		return (write (2, "Error\n", 6));
	}
	structure = init_struct(list, elements_count);
	if (argc == 2)
		free_tab(list);
	if (!structure)
		return (0);
	// printf("\n--- initial stack A ---\n");
	// for (t_node *printme = structure->head_a; printme != NULL; printme = printme->next)
	// 	printf("A: %i\n", printme->rank);
	push_swap(structure, structure->count);
	return (free_struct(structure), 0);
}

//for i in {0..101}; do echo $i; done | sort -R | tr '\n' ' '
// 20 66 73 2 15 50 86 18 56 85 72 53 17 58 84 90 14 79 68 70 38 82 25 42 100 49 65 39 91 5 33 69 45 24 81 98 93 6 67 62 41 51 44 35 26 77 52 23 80 74 3 55 43 8 97 89 36 47 10 78 76 96 60 37 12 4 71 59 0 32 13 64 83 95 94 29 7 48 1 19 34 11 -45 234 67465