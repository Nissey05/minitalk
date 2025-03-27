/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:15:11 by nhendrik          #+#    #+#             */
/*   Updated: 2024/10/28 11:52:51 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcheck(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_strrcheck(char const *str, char const *set)
{
	size_t	i;

	i = ft_strlen(str);
	while (--i > 0)
	{
		if (!ft_strchr(set, str[i]))
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	c1;
	size_t	c2;

	if (!s1 || !set)
		return (0);
	c1 = ft_strcheck(s1, set);
	c2 = ft_strrcheck(s1, set) - c1 + 1;
	return (ft_substr(s1, c1, c2));
}
