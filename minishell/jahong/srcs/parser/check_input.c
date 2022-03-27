/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:01:43 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 16:06:00 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quote(char *input)
{
	int		i;
	char	c;

	i = -1;
	c = 0;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			if (c == 0)
				c = input[i];
			else if (c == '\'' && input[i] == '\'')
				c = 0;
			else if (c == '"' && input[i] == '"')
				c = 0;
			else if (c == '\'' && input[i] == '"')
				continue ;
			else if (c == '"' && input[i] == '\'')
				continue ;
			else
				return (FALSE);
		}
	}
	return (c == 0);
}

int	check_input(char *input)
{
	int	i;
	int	cnt_space;

	i = -1;
	cnt_space = 0;
	if (input[0] == 0)
		return (FALSE);
	while (input[++i])
	{
		if (input[i] == '\t' || input[i] == '\v' || \
		input[i] == '\f' || input[i] == '\r')
			return (FALSE);
		else if (input[i] == ' ')
			++cnt_space;
	}
	if (cnt_space == ft_strlen(input))
		return (FALSE);
	if (check_quote(input) == FALSE)
	{
		ft_putstr_fd(ERR_QUOTE, STDERR);
		return (FALSE);
	}
	return (TRUE);
}
