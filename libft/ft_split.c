/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:09:46 by nhendrik          #+#    #+#             */
/*   Updated: 2025/01/16 17:15:20 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordlen(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (str[count] != c && str[count] != '\0')
		count++;
	return (count);
}

static size_t	ft_wordcount(const char *str, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	count = 0;
	while (str[i] || i < len)
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_freemem(char **str, size_t j)
{
	if (str[j] == NULL)
	{
		while (j--)
		{
			free(str[j]);
		}
		free(str);
	}
	return (NULL);
}

static char	**ft_splitloop(const char *s, char c, size_t *i, char **str)
{
	size_t	wlen;

	wlen = ft_wordlen(&s[i[0]], c);
	str[i[1]] = (char *)malloc(sizeof(char) * (wlen + 1));
	if (!str[i[1]])
		return (ft_freemem(str, i[1]));
	ft_strlcpy(str[i[1]], &s[i[0]], (wlen + 1));
	i[0] += wlen;
	while (s[i[0]] == c)
		i[0] += 1;
	return (str);
}

//i[0] used to be i
//i[1] used to be j
char	**ft_split(char const *s, char c)
{
	char			**str;
	size_t			i[2];
	size_t			count;

	i[0] = 0;
	count = ft_wordcount(s, c);
	while (s[i[0]] == c)
		i[0]++;
	str = (char **)ft_calloc(sizeof(char *), (count + 1));
	if (!str)
		return (NULL);
	i[1] = 0;
	while (i[1] < count)
	{
		if (!ft_splitloop(s, c, i, str))
			return (NULL);
		i[1]++;
	}
	return (str);
}