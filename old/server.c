/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:03:10 by nhendrik          #+#    #+#             */
/*   Updated: 2025/03/25 00:03:10 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


char	revert_bits(int input)
{
	int		i;
	char	output;

	i = 0;
	output = 0;
	while (i < 32)
	{
		if (input & 1)
			output = (output << 1) | 1;
		else
			output = output << 1;
		input = input >> 1;
		i++;
	}
	return (output);
}

void	reset_and_print(int *input, int *counter)
{
	printf("%c", revert_bits(*input));
	*input = 0;
	*counter = 0;
}

void	handle(int signal)
{
	static int	input = 0;
	static int	counter = 0;

	if (signal == SIGUSR1)
	{
		input = (input << 1) | 1;
		counter++;
	}
	else if (signal == SIGUSR2)
	{
		input = (input << 1);
		counter++;
	}
	if (counter >= 32)
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
