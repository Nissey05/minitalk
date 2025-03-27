/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:04:45 by nhendrik          #+#    #+#             */
/*   Updated: 2024/10/26 17:20:13 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	const char	*odst = dest;
	const char	*osrc = src;
	size_t		i;
	size_t		dest_len;

	i = n;
	while (i-- != 0 && *dest != '\0')
		dest++;
	dest_len = dest - odst;
	i = n - dest_len;
	if (i-- == 0)
		return (dest_len + ft_strlen(src));
	while (*src != '\0')
	{
		if (i != 0)
		{
			*dest++ = *src;
			i--;
		}
		src++;
	}
	*dest = '\0';
	return (dest_len + (src - osrc));
}
