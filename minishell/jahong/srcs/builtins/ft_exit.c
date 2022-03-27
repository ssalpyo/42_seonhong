/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:24:30 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/23 18:20:17 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_execute_err_1(char *token, char *err_msg)
{
	ft_putstr_fd("minishell", STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(token, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(err_msg, STDERR);
	return (-1);
}

static int	print_execute_err_2(char *token1, char *token2, char *err_msg)
{
	ft_putstr_fd("minishell", STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(token1, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(token2, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(err_msg, STDERR);
	return (-1);
}

void	ft_exit(char **cmd)
{
	int	ac;

	ac = 0;
	g_exit_status = 0;
	while (cmd[ac] != NULL)
		ac++;
	if (ac == 1)
		exit(g_exit_status);
	else if (ac == 2 && ft_isdigit_str(cmd[1]))
		g_exit_status = ft_atoi(cmd[1]);
	else if (ac > 2 && ft_isdigit_str(cmd[1]))
	{
		ft_putstr_fd("exit\n", STDERR);
		print_execute_err_1("exit", "too many arguments");
		return ;
	}
	else
	{
		print_execute_err_2("exit", cmd[1], "numeric argument required");
		exit(255);
	}
	exit(g_exit_status);
}
