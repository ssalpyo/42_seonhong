/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:20:39 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/22 16:55:16 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_input(char **input)
{
	char	*path;
	char	*temp;

	path = getcwd(0, MAX_WORKING_DIRECTORY_SIZE);
	temp = path;
	path = ft_strjoin(path, " $ ");
	*input = readline(path);
	free(temp);
	free(path);
	return (*input);
}
