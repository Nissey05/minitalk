/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:53:39 by nhendrik          #+#    #+#             */
/*   Updated: 2024/10/26 17:18:43 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*s3;
	char			*s4;

	s3 = (char *)s1;
	s4 = (char *)s2;
	i = 0;
	while (n > i)
	{
		if (s3[i] != s4[i])
			return ((unsigned char)s3[i] - (unsigned char)s4[i]);
		i++;
	}
	return (0);
}
