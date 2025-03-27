/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:42:15 by nhendrik          #+#    #+#             */
/*   Updated: 2024/10/26 17:21:56 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char	*dest_copy;
	unsigned char	*src_copy;

	if (dest == 0 && src == 0)
		return (0);
	dest_copy = (unsigned char *)dest;
	src_copy = (unsigned char *)src;
	while (n--)
	{
		dest_copy[n] = src_copy[n];
	}
	return (dest);
}
