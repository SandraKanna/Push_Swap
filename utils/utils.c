/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:49:11 by skanna            #+#    #+#             */
/*   Updated: 2024/01/23 17:17:27 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

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

int	do_atoi(const char *str, int *error)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	//while (*str == 32 || (*str >= 9 && *str <= 13))
	//	str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (*str)
	{
		num = (num * 10) + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(num * sign));
}

