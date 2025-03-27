/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:22:18 by nhendrik          #+#    #+#             */
/*   Updated: 2024/12/16 16:24:02 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_checkconv(va_list ptr, const char *str)
{
	if (*str == 's')
		return (ft_printstr(va_arg(ptr, char *)));
	else if (*str == 'c')
		return (ft_printchar(va_arg(ptr, int)));
	else if (*str == 'i' || *str == 'd')
		return (ft_printnbr(va_arg(ptr, int)));
	else if (*str == '%')
		return (ft_printchar('%'));
	else if (*str == 'u')
		return (ft_printunbr(va_arg(ptr, unsigned int)));
	else if (*str == 'x' || *str == 'X')
		return (ft_printhex(va_arg(ptr, int), *str));
	else if (*str == 'p')
		return (ft_printptr(va_arg(ptr, uintptr_t)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		plen;
	va_list	ptr;
	int		i;
	int		check;

	i = 0;
	plen = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check = ft_checkconv(ptr, &str[i + 1]);
			i++;
		}
		else
			check = ft_printchar(str[i]);
		if (check < 0)
			return (-1);
		plen += check;
		i++;
	}
	va_end(ptr);
	return (plen);
}
