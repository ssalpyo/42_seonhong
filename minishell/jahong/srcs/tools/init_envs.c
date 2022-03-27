/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:21:46 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/24 17:02:07 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**init_envs(char **env)
{
	char	**result;
	int		i;

	result = malloc(sizeof(char *) * (get_size_env(env) + 1));
	if (result == NULL)
		exit(-1);
	i = -1;
	while (env[++i])
		result[i] = ft_strdup(env[i]);
	result[i] = NULL;
	return (result);
}
