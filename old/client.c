/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:03:19 by nhendrik          #+#    #+#             */
/*   Updated: 2025/03/25 00:03:19 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void send_char(int c, int pid)
{
	int i;

	i = 0;
	while (i < 32)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		usleep(1000);
	}
}

void send_string(char *str, int pid)
{
	int i;

	i = 0;
	while (str[i])
	{
		send_char((int)str[i], pid);
		i++;
	}
	send_char('\n', pid);
}

int main(int argc, char **argv)
{
	int pid;
	
	if (argc != 3)
		return (write(2, "Incorrect Input\n", 16)-1);
	pid = atoi(argv[1]);
	send_string(argv[2], pid);
}