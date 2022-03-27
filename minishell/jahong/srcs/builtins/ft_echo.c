/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:04:27 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 19:33:38 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_option_n(char *token)
{
	int	i;

	if (ft_strncmp(token, "-n", 2) != 0)
		return (FALSE);
	i = 2;
	while (token[i])
	{
		if (token[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_echo(char **commands, char **envs)
{
	int	i;
	int	option;

	i = 1;
	option = OPTION_NONE;
	while (commands[i] && check_option_n(commands[i]))
	{
		option = OPTION_N;
		i++;
	}
	while (commands[i])
	{
		ft_putstr_fd(commands[i], STDOUT);
		if (commands[i + 1] != NULL)
			ft_putchar_fd(' ', STDOUT);
		i++;
	}
	if (option == OPTION_NONE)
		ft_putchar_fd('\n', STDOUT);
	g_exit_status = 0;
}
