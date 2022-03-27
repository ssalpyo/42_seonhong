/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:19:28 by jayi              #+#    #+#             */
/*   Updated: 2021/11/24 14:44:03 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtins(char **cmd, char ***envs_addr)
{
	if (cmd[0] == NULL)
		return (1);
	else if (!ft_strcmp(cmd[0], "cd"))
		exit(1);
	else if (!ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd, *envs_addr);
	else if (!ft_strcmp(cmd[0], "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp(cmd[0], "env"))
		ft_env(*envs_addr);
	else if (!ft_strcmp(cmd[0], "export"))
		ft_export(cmd, envs_addr, FALSE);
	else if (!ft_strcmp(cmd[0], "unset"))
		exit(1);
	else if (!ft_strcmp(cmd[0], "exit"))
		exit(1);
	else
		return (0);
	return (1);
}
