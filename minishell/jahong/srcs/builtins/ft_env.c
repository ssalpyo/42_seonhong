/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:02:32 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 18:05:01 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **envs)
{
	int	i;

	i = 0;
	while (envs[i])
	{
		write(STDOUT, envs[i], ft_strlen(envs[i]));
		write(STDOUT, "\n", 1);
		i++;
	}
	g_exit_status = 0;
}
