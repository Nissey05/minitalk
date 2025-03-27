/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:03:19 by nhendrik          #+#    #+#             */
/*   Updated: 2025/03/25 17:41:32 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len])
		len++;
	return (len);
}

void send_char(int c, int pid, int times)
{
	int i;

	i = 0;
	while (i < times)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		usleep(10000);
	}
}

void send_str_len(char *str, int pid)
{
	int len;

	len = (int)ft_strlen((const char *)str);
	send_char(len, pid, 32);
}

void send_string(char *str, int pid)
{
	int i;

	i = 0;
	while (str[i])
	{
		send_char((int)str[i], pid, 8);
		i++;
	}
}

int main(int argc, char **argv)
{
	int pid;
	
	if (argc != 3)
		return (write(2, "Incorrect Input\n", 16), -1);
	pid = atoi(argv[1]);
	send_str_len(argv[2], pid);
	send_string(argv[2], pid);
}