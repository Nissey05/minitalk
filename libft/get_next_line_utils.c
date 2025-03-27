/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:40:48 by nhendrik          #+#    #+#             */
/*   Updated: 2025/01/16 17:06:21 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

int	ft_strlen_nl(char *str)
{
	int	count;

	count = 0;
	while (str && str[count])
		count++;
	return (count);
}

int	calc_spare(int *spare)
{
	int	j;

	if (*spare > 0)
		j = BUFFER_SIZE - (*spare);
	else
		j = 0;
	return (j);
}
