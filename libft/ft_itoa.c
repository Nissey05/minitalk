/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:17:05 by nhendrik          #+#    #+#             */
/*   Updated: 2024/10/26 17:22:05 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count = ft_intlen(n / 10);
		return (++count);
	}
	else
		return (++count);
}

static unsigned int	ft_negcheck(unsigned int i, int n, int *neg)
{
	if (n < 0)
	{
		*neg = 1;
		i = -n;
	}
	else
		i = n;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*a;
	int				intlen;
	int				neg;
	unsigned int	i;

	neg = 0;
	i = 0;
	i = ft_negcheck(i, n, &neg);
	intlen = ft_intlen(i);
	a = (char *)malloc((neg + intlen + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	a[intlen + neg] = '\0';
	while (--intlen >= 0)
	{
		a[intlen + neg] = (i % 10) + '0';
		i /= 10;
	}
	if (neg)
		a[0] = '-';
	return (a);
}
