/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:25:44 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/24 14:50:55 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env(char **envs)
{
	int	i;

	i = -1;
	while (envs[++i])
		ft_putendl_fd(envs[i], STDOUT);
}

static void	insert_env(char **cmd, int idx, char ***envs_addr)
{
	int		env_idx;
	char	*key;

	if (ft_strchr(cmd[idx], '=') == NULL)
	{
		env_idx = find_env_var(cmd[idx], *envs_addr);
		if ((*envs_addr)[env_idx] != NULL)
			return ;
		realloc_env(env_idx + 1, envs_addr);
		(*envs_addr)[env_idx] = ft_strjoin(cmd[idx], "=");
	}
	else
	{
		key = ft_substr(cmd[idx], 0, ft_strchr(cmd[idx], '=') - cmd[idx]);
		env_idx = find_env_var(key, *envs_addr);
		free(key);
		if ((*envs_addr)[env_idx] == NULL)
			realloc_env(env_idx + 1, envs_addr);
		free((*envs_addr)[env_idx]);
		(*envs_addr)[env_idx] = ft_strdup(cmd[idx]);
	}
}

void	ft_export(char **cmd, char ***envs_addr, int global)
{
	int	i;

	g_exit_status = 0;
	if (global == FALSE && cmd[1] == NULL)
		print_env(*envs_addr);
	i = 0;
	while (global == TRUE && cmd[++i] != NULL)
	{
		if (is_redipe(cmd[i]))
			return ;
		insert_env(cmd, i, envs_addr);
	}
}
