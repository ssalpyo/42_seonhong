/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_inputs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:34:27 by jayi              #+#    #+#             */
/*   Updated: 2021/11/24 17:02:07 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**normalize_inputs(char **inputs, char **envs)
{
	char	**cur;
	char	**result;
	char	*normalized;

	cur = inputs;
	normalized = ft_strdup("");
	while (*cur)
	{
		normalize_input(&normalized, *cur, envs);
		cur++;
	}
	result = ft_split(normalized, SPERATOR);
	free(normalized);
	return (result);
}
