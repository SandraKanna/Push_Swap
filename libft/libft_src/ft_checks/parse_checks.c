/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:37:04 by skanna            #+#    #+#             */
/*   Updated: 2024/02/14 11:22:49 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/libftv3.h"

int	has_quotes(char const *str)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			quotes++;
		i++;
	}
	if (quotes % 2 == 0)
		return (1);
	else if (quotes == 0)
		return (0);
	return (-1);
}
