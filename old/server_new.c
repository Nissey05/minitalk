/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:03:10 by nhendrik          #+#    #+#             */
/*   Updated: 2025/03/25 17:37:33 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	revert_bits(int input, int amount)
{
	int		i;
	int		output;

	i = 0;
	output = 0;
	while (i < amount)
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

int	calc_len(int signal, int *calcing, int ret)
{
	static int i = 0;

	if (i < 31)
	{
		if (signal == SIGUSR1)
			ret = (ret << 1) | 1;
		else
			ret = ret << 1;
		i++;
	}
	else
	{
		ret = revert_bits(ret, 31);
		*calcing = 0;
		i = 0;
	}
	return (ret);
}

void	reset_and_print(int *input, int *counter, int *len, char **out)
{
	int i;

	i = 0;
	while(out[0][i])
		i++;
	out[0][i] = (char)revert_bits(*input, 8);
	*input = 0;
	*counter = 0;
	(*len)--;
	if (*len == 0)
	{
		ft_printf("%s\n", *out);
		free(*out);
		*out = NULL;
	}
}

void	handle(int signal)
{
	static int	input = 0;
	static int	counter = 0;
	static int	len = 0;
	static int	calcing = 0;
	static char	*out = NULL;

	if (len <= 0)
		calcing = 1;
	if (!calcing && !out)
		out = (char *)ft_calloc(len, sizeof(char));
	if (calcing)
		len = calc_len(signal, &calcing, len);
	else
	{
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
	}
	if (counter >= 8)
		reset_and_print(&input, &counter, &len, &out);
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
