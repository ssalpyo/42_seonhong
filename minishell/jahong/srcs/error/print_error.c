/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:47 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 16:16:57 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *err_target, char *err_msg, char *err_arg)
{
	if (err_target != NULL)
		ft_putstr_fd(err_target, STDERR);
	if (err_msg != NULL)
	{
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(err_msg, STDERR);
	}
	if (err_arg != NULL)
	{
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(err_arg, STDERR);
	}
	return (g_exit_status);
}
