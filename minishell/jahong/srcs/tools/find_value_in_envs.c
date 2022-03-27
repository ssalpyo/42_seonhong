/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value_in_envs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:00:44 by jayi              #+#    #+#             */
/*   Updated: 2021/11/22 20:43:46 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_value_in_envs(char *key, char **envs)
{
	int	i;

	if (ft_strcmp(key, "?") == 0)
		return (ft_itoa(g_exit_status));
	if (ft_strlen(key) == 0)
		return ("");
	i = -1;
	while (envs[++i])
	{
		if (!ft_strncmp(envs[i], key, ft_strlen(key)))
			return (envs[i] + ft_strlen(key) + 1);
	}
	return ("");
}
