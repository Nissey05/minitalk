/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:08:48 by nhendrik          #+#    #+#             */
/*   Updated: 2024/11/27 11:04:38 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/* ***************************** */
/* ft_memcpy iterates backwards! */
/* ***************************** */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dest2;
	size_t			i;

	if (dest == 0 && src == 0)
		return (0);
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (&src2[0] < &dest2[0])
		return (ft_memcpy(dest, src, n));
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
