/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:06:12 by seonhong          #+#    #+#             */
/*   Updated: 2021/09/26 21:46:52 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(pid_t pid, const char *str, size_t len)
{
	size_t	i;
	int		shift;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 8)
		{
			if (kill(pid, SIGUSR1 + (((str[i] >> shift) & 1) > 0)) == -1)
				ft_error();
			shift++;
			usleep(100);
		}
		i++;
	}
}

void	check_receive(int signal)
{
	(void)signal;
	write(1, "Signal received\n", 16);
	exit(0);
}

int	main(int argc, const char **argv)
{
	pid_t	pid;

	if (argc != 3 || !argv || !ft_isdigit_str(argv[1]))
		ft_error();
	pid = ft_atoi(argv[1]);
	if (pid > 2147483647 || pid <= 0)
		ft_error();
	signal(SIGUSR2, check_receive);
	send_char(pid, argv[2], ft_strlen(argv[2]));
	while (1)
		pause();
	return (0);
}
