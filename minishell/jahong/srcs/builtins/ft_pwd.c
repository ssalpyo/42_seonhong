/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:58:35 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 19:27:51 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **cmd)
{
	char	*pwd;

	if (cmd[1])
	{
		ft_putendl_fd("pwd: Too many arguments.", STDERR);
		g_exit_status = 1;
		return ;
	}
	pwd = getcwd(0, MAX_WORKING_DIRECTORY_SIZE);
	ft_putendl_fd(pwd, 1);
	free(pwd);
	g_exit_status = 0;
}
