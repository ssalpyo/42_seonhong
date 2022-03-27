/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:19:59 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 16:21:40 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_key(char *str)
{
	int		idx;
	char	*key;

	idx = 0;
	if (str[idx] == '?')
		return (ft_strdup("?"));
	while (str[idx] != '\0' && str[idx] != ' ' && \
		str[idx] != '"' && str[idx] != '\'')
		idx++;
	key = ft_substr(str, 0, idx);
	return (key);
}
