/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:56:42 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/25 00:55:38 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	run_cmd(char *path, char **args, char **envs)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, envs);
	else if (pid < 0)
	{
		free(path);
		print_error("minishell", "Fork failed to create a new process.", NULL);
		return (-1);
	}
	wait(&g_exit_status);
	g_exit_status = WEXITSTATUS(g_exit_status);
	if (path)
		free(path);
	return (g_exit_status);
}

static int	run_cmd_in_path(char **cmd, char **envs)
{
	struct stat	f;
	char		**paths;
	char		*temp;

	paths = ft_split(get_env_var("PATH", envs), ':');
	while (paths != NULL && *paths)
	{
		temp = *paths;
		*paths = ft_strjoin(*paths, "/");
		free(temp);
		temp = ft_strjoin(*paths, cmd[0]);
		if (lstat(temp, &f) != -1)
		{
			run_cmd(ft_strdup(temp), cmd, envs);
			free(temp);
			return (1);
		}
		free(temp);
		paths++;
	}
	return (0);
}

static void	run_cmd_on_child(char **cmd, char ***envs_addr)
{
	// struct stat	f;

	// f.st_mode = 0;
	run_redipe(cmd);
	if (exec_builtins(cmd, envs_addr))
		exit(g_exit_status);
	// lstat(cmd[0], &f);
	// if (ft_strchr(cmd[0], '/') && f.st_mode & S_IXUSR)
	// 	exit(run_cmd(ft_strdup(cmd[0]), cmd, *envs_addr));
	// else if (run_cmd_in_path(cmd, *envs_addr))
	if (run_cmd_in_path(cmd, *envs_addr))
		exit(g_exit_status);
	print_error("minishell", "command not found", cmd[0]);
	exit(COMMAND_NOT_FOUND);
}

static int	pre_exec_builtins(char **cmd, char ***envs_addr)
{
	struct stat	f;

	if (cmd[0] == NULL)
		return (1);
	f.st_mode = 0;
	lstat(cmd[0], &f);
	if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd);
	else if (ft_strcmp(cmd[0], "export") == 0)
		ft_export(cmd, envs_addr, TRUE);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (ft_unset(cmd, envs_addr));
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd, envs_addr));
	else if (f.st_mode & S_IFDIR)
		return (change_dir(cmd[0], 0, envs_addr));
	return (0);
}

void	execute_cmd(char **cmd, char ***envs_addr)
{
	int	pid;
	int	status;

	if (pre_exec_builtins(cmd, envs_addr))
	{
		free_strs(cmd);
		return ;
	}
	init_signal(signal_none_handler);
	pid = fork();
	if (pid == 0)
		run_cmd_on_child(cmd, envs_addr);
	else
	{
		wait(&status);
		init_signal(signal_handler);
		g_exit_status = WEXITSTATUS(status);
	}
	free_strs(cmd);
}
