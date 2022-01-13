/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:12:31 by bokim             #+#    #+#             */
/*   Updated: 2022/01/13 19:34:34 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/minitalk.h"

int	get_server_pid(int argc, char *argv[])
{
	int	s_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong arguments : [1]filename [2]pid [3]message\n", 2);
		exit(1);
	}
	s_pid = ft_atoi(argv[1]);
	if (s_pid < 100 || s_pid > 99998)
	{
		ft_putstr_fd("Wrong pid\n", 2);
		exit(1);
	}
	return (s_pid);
}

void	send_signal(int	s_pid, int byte)
{
	int	digit;

	digit = 0;
	while (digit <= 7)
	{
		if ((byte >> digit) & 1)
		{
			if (kill(s_pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Signal Error : from Client\n", 2);
				exit(1);
			}
		}
		else
		{
			if (kill(s_pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Signal Error : from Client\n", 2);
				exit(1);
			}
		}
		digit++;
		usleep(100);
	}
}

void	send(int s_pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send_signal(s_pid, msg[i++]);
	}
	ft_printf("Server received message\n");
}

int	main(int argc, char *argv[])
{
	int	s_pid;

	s_pid = get_server_pid(argc, argv);
	send(s_pid, argv[2]);
	return (0);
}
