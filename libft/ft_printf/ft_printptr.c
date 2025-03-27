/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:38:38 by nhendrik          #+#    #+#             */
/*   Updated: 2024/12/16 16:28:05 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t n)
{
	int			count;
	int			check;
	const char	*conv = "0123456789abcdef";

	count = 0;
	if (n > 15)
	{
		check = ft_putptr(n / 16);
		if (check < 0)
			return (-1);
		count += check;
	}
	check = ft_printchar(conv[n % 16]);
	if (check < 0)
		return (-1);
	count += check;
	n /= 16;
	return (count);
}

int	ft_printptr(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_printstr("(nil)"));
	count += ft_printstr("0x");
	count += ft_putptr(ptr);
	return (count);
}
