/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:06:16 by seonhong          #+#    #+#             */
/*   Updated: 2021/09/26 21:13:35 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *siginfo, void *unused)
{
	static t_msg	msg;

	(void)unused;
	msg.c += ((signal & 1) << msg.size);
	msg.size++;
	if (msg.size == 8)
	{
		ft_putchar_fd(msg.c, 1);
		if (!msg.c)
		{
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_error();
			write(1, "\n", 1);
		}
		msg = (t_msg){0, 0};
	}
}

int	main(void)
{
	struct sigaction	catch;

	write(1, "Server PID : ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = signal_handler;
	while (1)
	{
		sigaction(SIGUSR1, &catch, 0);
		sigaction(SIGUSR2, &catch, 0);
		pause();
	}
	return (0);
}
