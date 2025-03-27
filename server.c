/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:03:10 by nhendrik          #+#    #+#             */
/*   Updated: 2025/03/26 18:57:55 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

volatile static int g_inforeceived[2] = {0, 0};

void	reset_and_print(int *input, int *counter, int zero)
{
	static char str[131072];
	int			i;

	i = 0;
	while (str[i])
		i++;
	str[i] = (char)(*input);
	if (str[i] == '\n' && !zero)
	{
		printf("%s", str);
		ft_bzero(str, ft_strlen(str));
	}
	if (zero)
		ft_bzero((str), ft_strlen(str));
	*input = 0;
	*counter = 0;
}

void	calc_bit()
{
	static int	input = 0;
	static int	counter = 0;
	static int	previous = 0;

	if (previous != g_inforeceived[1])
	{
		reset_and_print(&input, &counter, 1);
		kill(previous, SIGUSR2);
		previous = g_inforeceived[1];
	}
	if (g_inforeceived[0] == SIGUSR1)
	{
		input = (input >> 1) | (1 << 7);
		counter++;
	}
	else if (g_inforeceived[0] == SIGUSR2)
	{
		input = (input >> 1);
		counter++;
	}
	if (counter >= 8)
		reset_and_print(&input, &counter, 0);
}

void	handle(int signal, siginfo_t *info, void *c)
{
	g_inforeceived[0] = signal;
	g_inforeceived[1] = info->si_pid;
	(void)c;
}

int	main(void)
{
	struct sigaction sig;
	int	pid;

	pid = getpid();
	printf("%d\n", pid);
	sig.sa_sigaction = handle;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		while (!g_inforeceived[0])
			usleep(1);
		calc_bit();
		g_inforeceived[0] = 0;
		kill(g_inforeceived[1], SIGUSR1);
	}
}

