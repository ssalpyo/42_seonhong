/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:07:56 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/24 17:02:07 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envs)
{
	char	*input;
	char	**cmd;

	init_signal(signal_handler);
	envs = init_envs(envs);
	while (read_input(&input))
	{
		if (check_input(input) == FALSE)
		{
			free(input);
			continue ;
		}
		add_history(input);
		cmd = ft_split_ms(input, ' ');
		free(input);
		execute_cmd(normalize_inputs(cmd, envs), &envs);
		free_strs(cmd);
	}
	free_strs(envs);
	return (1);
}
