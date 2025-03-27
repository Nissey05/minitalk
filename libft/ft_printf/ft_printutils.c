/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:34:37 by nhendrik          #+#    #+#             */
/*   Updated: 2024/12/16 16:10:15 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(const char *s)
{
	int	i;

	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_printchar('-');
		if (i < 0)
			return (-1);
		if (n == -2147483648)
			return (ft_printstr("2147483648") + 1);
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_printnbr(n / 10);
		if (ft_printchar((n % 10) + '0') < 0)
			return (-1);
	}
	else
	{
		if (ft_printchar(n + '0') < 0)
			return (-1);
	}
	return (++i);
}

int	ft_printunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_printunbr(n / 10);
		if (ft_printchar((n % 10) + '0') < 0)
			return (-1);
	}
	else
	{
		if (ft_printchar(n + '0') < 0)
			return (-1);
	}
	return (++i);
}
