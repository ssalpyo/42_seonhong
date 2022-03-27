/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:26:06 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/24 14:51:20 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_env_var(int var_pos, char ***envs_addr)
{
	int			i;
	int			var_count;
	const char	**envs = (const char **)*envs_addr;

	free((void *)envs[var_pos]);
	envs[var_pos] = NULL;
	i = var_pos;
	var_count = var_pos + 1;
	while (envs[i + 1])
	{
		envs[i] = ft_strdup(envs[i + 1]);
		free((void *)envs[i + 1]);
		i++;
		var_count++;
	}
	*envs_addr = realloc_env(var_count - 1, envs_addr);
}

int	ft_unset(char **cmd, char ***envs_addr)
{
	int	i;
	int	var_pos;

	g_exit_status = 0;
	if (!cmd[1])
	{
		ft_putendl_fd("unset: not enough arguments", STDERR);
		g_exit_status = 1;
		return (0);
	}
	i = 0;
	while (cmd[++i])
	{
		if (is_redipe(cmd[i]))
			return (1);
		var_pos = find_env_var(cmd[i], *envs_addr);
		if ((*envs_addr)[var_pos])
			remove_env_var(var_pos, envs_addr);
	}
	return (1);
}
