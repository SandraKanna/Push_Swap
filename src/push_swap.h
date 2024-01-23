/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:44:01 by skanna            #+#    #+#             */
/*   Updated: 2024/01/23 17:27:49 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

char	**parse_args(int *ac, int argc, char **av);
int		check_errors(int ac, char **av);
size_t	ft_strlen(const char *str);
char	*ft_vide(void);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		do_atoi(const char *str, int *error);
char	*ft_strdup(const char *s);
void	free_args(char **av);

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

void	add_to_stack(t_node **stack, int input);
int		remove_from_stack(t_node **stack);
void	free_stack(t_node **stack);

#endif