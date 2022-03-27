/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:18:51 by jayi              #+#    #+#             */
/*   Updated: 2021/11/24 14:54:36 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_dir(char *path, int print_path, char ***envs_addr)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		g_exit_status = 0;
		if (print_path)
			ft_putendl_fd(path, STDOUT);
		set_env_var("OLDPWD", cwd, envs_addr);
	}
	else
	{
		print_error("cd", strerror(errno), path);
		g_exit_status = 1;
		return (0);
	}
	return (1);
}

int	ft_cd(char **cmd, char ***envs_addr)
{
	char	*home_path;

	home_path = get_env_var("HOME", *envs_addr);
	if (!cmd[1])
		return (change_dir(home_path, 0, envs_addr));
	else
		return (change_dir(cmd[1], 0, envs_addr));
}
