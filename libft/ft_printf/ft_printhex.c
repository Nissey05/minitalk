/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:00:50 by nhendrik          #+#    #+#             */
/*   Updated: 2024/12/16 16:22:12 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count = ft_hexlen(n / 16);
		return (++count);
	}
	else
		return (++count);
}

int	ft_printhex(unsigned int n, char c)
{
	const char	*conv = "0123456789ABCDEFabcdef";
	int			count;
	int			check;

	count = 0;
	check = 0;
	if (n > 15)
	{
		check = ft_printhex(n / 16, c);
		if (check < 0)
			return (-1);
		count += check;
	}
	if (c == 'x' && n % 16 >= 10 && n % 16 <= 16)
		check = ft_printchar(conv[n % 16 + 6]);
	else
		check = ft_printchar(conv[n % 16]);
	if (check < 0)
		return (-1);
	count += check;
	n /= 16;
	return (count);
}
