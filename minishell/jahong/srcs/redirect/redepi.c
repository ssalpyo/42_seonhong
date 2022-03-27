/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redepi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:33:21 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 19:29:25 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	right_redirect(char **cmd, int i, int flag)
{
	int	fd;

	fd = open(cmd[i + 1], flag, 0744);
	if (fd <= 0)
		return (-1);
	dup2(fd, STDOUT);
	close(fd);
	return (fd);
}

int	left_redirect(char **cmd, int i)
{
	int	fd;

	fd = open(cmd[i + 1], O_RDONLY, 0644);
	if (fd <= 0)
		return (-1);
	dup2(fd, STDIN);
	close(fd);
	return (fd);
}

int	lleft_redirect(char **cmd, int i)
{
	char	*line;
	int		_pipe[2];
	int		pid;

	pipe(_pipe);
	pid = fork();
	if (pid == 0)
	{
		close(_pipe[READ]);
		while (TRUE)
		{
			line = readline("heredoc> ");
			if (ft_strncmp(line, cmd[i + 1], ft_strlen(cmd[i + 1])))
				ft_putendl_fd(line, _pipe[WRITE]);
			else
				exit(0);
		}
	}
	else
	{
		close(_pipe[WRITE]);
		waitpid(pid, &i, 0);
		dup2(_pipe[READ], STDIN);
	}
	return (0);
}

void	pipe_on_parent(int *_pipe, int pid, int i, char **cmd)
{
	int		idx;
	char	*temp;
	int		status;

	idx = 0;
	close(_pipe[WRITE]);
	dup2(_pipe[READ], STDIN);
	waitpid(pid, &status, 0);
	while (idx <= i)
	{
		free(cmd[idx]);
		cmd[idx] = NULL;
		idx++;
	}
	idx = 0;
	i = i + 1;
	while (cmd[i])
	{
		temp = cmd[idx];
		cmd[idx] = cmd[i];
		cmd[i] = temp;
		idx++;
		i++;
	}
}

int	ms_pipe(char **cmd, int i)
{
	int	_pipe[2];
	int	pid;

	pipe(_pipe);
	pid = fork();
	if (pid == 0)
	{
		close(_pipe[READ]);
		dup2(_pipe[WRITE], STDOUT);
		while (cmd[i])
		{
			free(cmd[i]);
			cmd[i] = NULL;
			i++;
		}
	}
	else
		pipe_on_parent(_pipe, pid, i, cmd);
	return (0);
}
