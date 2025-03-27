/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:03:19 by nhendrik          #+#    #+#             */
/*   Updated: 2025/03/27 13:33:23 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static int g_bitreceived = 0;

int	send_char(int c, int pid)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		while (!g_bitreceived)
			usleep(1);
		if (g_bitreceived == -1)
			return (0);
		g_bitreceived = 0;
	}
	return (1);
}

void send_string(char *str, int pid)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!send_char((int)str[i], pid))
			return ;
		i++;
	}
	send_char('\n', pid);
}

void	handle(int signal)
{
	if (signal == SIGUSR2)
		g_bitreceived = -1;
	else
		g_bitreceived = 1;
}

int main(int argc, char **argv)
{
	int pid;
	
	if (argc != 3)
		return (write(2, "Incorrect Input\n", 16)-1);
	pid = atoi(argv[1]);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	send_string(argv[2], pid);
}