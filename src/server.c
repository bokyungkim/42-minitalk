/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:12:29 by bokim             #+#    #+#             */
/*   Updated: 2022/01/11 19:12:05 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/minitalk.h"

void	handler(int signo, siginfo_t *siginfo, void *unused)
{
	static unsigned char	msg = 0;
	static int				digit = 0;

	unused = 0;
	if (signo == SIGUSR1)
		msg |= (1 << digit);
	digit++;
	if (digit == 8)
	{
		// write(1, &msg, 1);
		ft_printf("%c", msg);
		digit = 0;
		msg = 0;
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
			ft_putstr_fd("Signal Error : from Server\n", 1);
	}
}

int	main(void)
{
	struct sigaction act;

	ft_putstr_fd("SERVER PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n====================\n", 1);
	act.sa_flags = SA_SIGINFO; //sigaction을 사용하겠다.
	act.sa_sigaction = &handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_putstr_fd("Sigaction Error\n", 1);
		exit(1);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_putstr_fd("Sigaction Error\n", 1);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}