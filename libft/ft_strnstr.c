/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:45:41 by nhendrik          #+#    #+#             */
/*   Updated: 2024/10/28 14:15:27 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_needleloop(size_t i, size_t n,
						const char *haystack, const char *needle)
{
	int		k;
	size_t	correct;

	correct = 1;
	k = 0;
	while (needle[k])
	{
		if (needle[k] != haystack[i + k])
		{
			correct = 0;
			break ;
		}
		if (i + k >= n)
		{
			correct = 0;
			break ;
		}
		k++;
	}
	return (correct);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	correct;

	correct = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < n && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			correct = ft_needleloop(i, n, haystack, needle);
		}
		if (correct)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
