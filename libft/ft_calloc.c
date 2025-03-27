/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:12:39 by nhendrik          #+#    #+#             */
/*   Updated: 2024/10/26 17:11:09 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t n)
{
	void	*ptr;

	if (count != 0 && n != 0)
	{
		if (SIZE_MAX / count < n)
			return (NULL);
		if (SIZE_MAX / n < count)
			return (NULL);
	}
	ptr = malloc(count * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * n);
	return (ptr);
}
