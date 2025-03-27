/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_newnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:03:10 by nhendrik          #+#    #+#             */
/*   Updated: 2025/03/25 19:59:14 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	reset_and_print(int *input, int *counter)
{
	static char str[131072];
	int			i;

	i = 0;
	while (str[i])
		i++;
	str[i] = (char)(*input);
	if (str[i] == '\n')
	{
		printf("%s", str);
		ft_bzero(str, ft_strlen(str));
	}
	*input = 0;
	*counter = 0;
}

void	handle(int signal)
{
	static int	input = 0;
	static int	counter = 0;

	if (signal == SIGUSR1)
	{
		input = (input >> 1) | (1 << 7);
		counter++;
	}
	else if (signal == SIGUSR2)
	{
		input = (input >> 1);
		counter++;
	}
	if (counter >= 8)
		reset_and_print(&input, &counter);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
		pause();
}
