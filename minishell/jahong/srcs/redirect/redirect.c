/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:25:11 by jayi              #+#    #+#             */
/*   Updated: 2021/11/24 14:53:15 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redipe(char *str)
{
	if (ft_strcmp(str, ">>") == 0)
		return (RRIGHT_REDIRECT);
	else if (ft_strcmp(str, ">") == 0)
		return (RIGHT_REDIRECT);
	else if (ft_strcmp(str, "<<") == 0)
		return (LLEFT_REDIRECT);
	else if (ft_strcmp(str, "<") == 0)
		return (LEFT_REDIRECT);
	else if (ft_strcmp(str, "|") == 0)
		return (PIPE);
	return (FALSE);
}

static int	get_cmd_size(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

void	shift_cmd(char **cmd, int i)
{
	char	*temp;
	int		cmd_length;

	cmd_length = get_cmd_size(cmd);
	free(cmd[i]);
	free(cmd[i + 1]);
	cmd[i] = NULL;
	cmd[i + 1] = NULL;
	while (i + 2 < cmd_length)
	{
		temp = cmd[i + 2];
		cmd[i + 2] = cmd[i];
		cmd[i] = temp;
		i++;
	}
}

static int	run(int ret, int *i, char **cmd)
{
	if (ret == LLEFT_REDIRECT)
		return (lleft_redirect(cmd, *i));
	else if (ret == LEFT_REDIRECT)
		return (left_redirect(cmd, *i));
	else if (ret == RRIGHT_REDIRECT)
		return (right_redirect(cmd, *i, O_WRONLY | O_CREAT | O_APPEND));
	else if (ret == RIGHT_REDIRECT)
		return (right_redirect(cmd, *i, O_WRONLY | O_CREAT | O_TRUNC));
	else if (ret == PIPE)
	{
		ms_pipe(cmd, *i);
		*i = -1;
	}
	return (0);
}

void	run_redipe(char **cmd)
{
	int	i;
	int	ret;
	int	err;

	i = -1;
	while (cmd[++i])
	{
		ret = is_redipe(cmd[i]);
		err = run(ret, &i, cmd);
		if (err < 0)
			exit(print_error("minishell", strerror(errno), cmd[i + 1]));
		if (ret != 0 && ret != PIPE)
			shift_cmd(cmd, i--);
	}
}
