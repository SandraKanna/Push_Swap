/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:49:11 by skanna            #+#    #+#             */
/*   Updated: 2024/01/22 16:33:23 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	free_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free (av);
}

static char	*ft_vide(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*substr;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s || !len)
		return (ft_vide());
	if (len > len_s)
		len = len_s;
	if (len > len_s - start)
		len = len_s - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**check_in_quotes(int *ac, char **av)
{
	char	**split_av;
	int		index;

	split_av = ft_split(av[1], ' ');
	if (!split_av)
		exit(EXIT_FAILURE);
	index = 0;
	while (split_av[index] != NULL)
		index++;
	*ac = index;
	//	printf("Test in quotes: ac = %i\n", ac);
	return (split_av);
}
