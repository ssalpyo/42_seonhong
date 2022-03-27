/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:53:08 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/24 10:23:27 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**realloc_env(int new_size, char ***envs_addr)
{
	char	**new;
	char	**cur;
	int		i;

	cur = *envs_addr;
	new = malloc(sizeof(char *) * (new_size + 1));
	if (!new)
		return (0);
	i = -1;
	while (cur[++i] && i < new_size)
	{
		new[i] = ft_strdup(cur[i]);
		free(cur[i]);
	}
	free(cur);
	new[new_size] = NULL;
	*envs_addr = new;
	return (new);
}

int	find_env_var(char *var, char **envs)
{
	int		i;
	char	*tmp;

	i = -1;
	while (envs[++i])
	{
		tmp = ft_strjoin(var, "=");
		if (!ft_strncmp(envs[i], tmp, ft_strlen(tmp)))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (i);
}

char	*get_env_var(char *var, char **envs)
{
	int		i;
	char	*tmp;

	i = -1;
	while (envs[++i])
	{
		tmp = ft_strjoin(var, "=");
		if (ft_strncmp(envs[i], tmp, ft_strlen(tmp)) == 0)
		{
			free(tmp);
			return (ft_strchr(envs[i], '=') + 1);
		}
		free(tmp);
	}
	return (NULL);
}

void	set_env_var(char *key, char *cwd, char ***envs_addr)
{
	char	**envs;
	char	*tmp;
	int		i;

	envs = *envs_addr;
	i = find_env_var(key, envs);
	tmp = ft_strjoin("=", cwd);
	if (envs[i])
	{
		free((void *)envs[i]);
		if (cwd)
			envs[i] = ft_strjoin(key, tmp);
		else
			envs[i] = ft_strjoin(key, "=");
	}
	else
	{
		realloc_env(i + 1, envs_addr);
		if (cwd)
			(*envs_addr)[i] = ft_strjoin(key, tmp);
		else
			(*envs_addr)[i] = ft_strjoin(key, "=");
	}
	free(tmp);
}
