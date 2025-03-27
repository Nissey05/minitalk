/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:52:11 by nhendrik          #+#    #+#             */
/*   Updated: 2025/02/16 16:52:35 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include <limits.h>

long	ft_atol(const char *nptr)
{
	size_t	i;
	long	count;
	int		neg;

	i = 0;
	count = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		count *= 10;
		count += neg * (nptr[i] - '0');
		i++;
	}
	if (nptr[i]  != '\0' && nptr[i] != ' ')
		return (0);
	return (count);
}