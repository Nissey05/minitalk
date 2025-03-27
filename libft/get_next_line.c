/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:58:57 by nhendrik          #+#    #+#             */
/*   Updated: 2025/01/16 17:06:13 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_read(int fd, char *buff, int *spare)
{
	int	i;
	int	readlen;
	int	spos;

	if (!(*spare > 0))
	{
		ft_bzero(buff, BUFFER_SIZE);
		readlen = read(fd, buff, BUFFER_SIZE);
		i = 0;
	}
	else
	{
		readlen = BUFFER_SIZE;
		i = BUFFER_SIZE - *spare;
	}
	if (readlen < 0)
		return (-1);
	spos = i;
	while (readlen > i && buff[i])
	{
		if (buff[i] == '\n')
			return (++i - spos);
		i++;
	}
	return (i - spos);
}

char	*copy_line(int *spare, char *buff, char **str, const int new_len)
{
	int			j;
	int			i;
	char		*str_copy;
	const int	curr_len = ft_strlen_nl(*str);

	i = 0;
	str_copy = (char *)malloc(sizeof(char) * (new_len + curr_len + 1));
	if (!str_copy)
		return (NULL);
	while (i < curr_len)
	{
		str_copy[i] = (*str)[i];
		i++;
	}
	i = 0;
	j = calc_spare(spare);
	while (i < new_len)
		str_copy[i++ + curr_len] = buff[j++];
	str_copy[i + curr_len] = '\0';
	if (*str)
		free(*str);
	*str = str_copy;
	return (*str);
}

int	make_line(int fd, char **str, char *buff, int *spare)
{
	int			j;
	const int	new_len = ft_read(fd, buff, spare);

	if (new_len < 0)
		return (-1);
	if (new_len == 0)
	{
		*spare = 0;
		return (1);
	}
	if (!copy_line(spare, buff, str, new_len))
		return (-1);
	j = calc_spare(spare);
	if (buff[j + new_len - 1] == '\n')
	{
		*spare = BUFFER_SIZE - (j + new_len);
		return (1);
	}
	else
		*spare = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*str;
	int			result;
	static int	spare = 0;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = 0;
	while (result == 0)
		result = make_line(fd, &str, buff, &spare);
	if (result == -1)
	{
		if (str)
			free(str);
		return (NULL);
	}
	return (str);
}
