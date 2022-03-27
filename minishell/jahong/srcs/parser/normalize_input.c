/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:21:56 by jayi              #+#    #+#             */
/*   Updated: 2021/11/24 10:49:05 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_quote(char ch, int clear)
{
	static char	saved = 0;

	if (clear == TRUE)
	{
		saved = 0;
		return (FALSE);
	}
	if (saved == 0 && (ch == '\'' || ch == '"'))
	{
		saved = ch;
	}
	else if (saved != 0 && saved == ch)
	{
		saved = 0;
		return (TRUE);
	}
	return (saved == ch);
}

static void	sperate_normalized(char **normalized, char *sep)
{
	char	*temp;

	ft_strjoin_char(normalized, SPERATOR);
	temp = *normalized;
	*normalized = ft_strjoin(*normalized, sep);
	ft_strjoin_char(normalized, SPERATOR);
	free(temp);
}

static int	process_sperator(char **normalized, char *src, t_normalize *var)
{
	if (var->quote != 0)
		return (FALSE);
	if (ft_strncmp(src, ">>", 2) == 0)
	{
		sperate_normalized(normalized, ">>");
		var->idx += 1;
	}
	else if (ft_strncmp(src, "<<", 2) == 0)
	{
		sperate_normalized(normalized, "<<");
		var->idx += 1;
	}
	else if (*src == '<')
		sperate_normalized(normalized, "<");
	else if (*src == '>')
		sperate_normalized(normalized, ">");
	else if (*src == '|')
		sperate_normalized(normalized, "|");
	else
		return (FALSE);
	return (TRUE);
}

static void	process_env(char **normalized, char *src, t_normalize *var)
{
	char	*key;
	char	*value;
	char	*temp;

	key = extract_key(&src[var->idx + 1]);
	value = find_value_in_envs(key, var->env);
	temp = *normalized;
	*normalized = ft_strjoin(*normalized, value);
	var->idx += ft_strlen(key);
	free(temp);
}

void	normalize_input(char **normalized, char *src, char **envs)
{
	t_normalize	var;
	char		*temp;

	var = (t_normalize){-1, 0, envs};
	while (src[++var.idx])
	{
		if (var.quote != '\'' && src[var.idx] == '$')
			process_env(normalized, src, &var);
		else if (ft_strcmp(src, "~") == 0)
			ft_strjoin_ref(normalized, get_env_var("HOME", envs));
		else if (is_valid_quote(src[var.idx], FALSE))
		{
			if (var.quote == 0)
				var.quote = src[var.idx];
			else
				var.quote = 0;
		}
		else if (process_sperator(normalized, &src[var.idx], &var))
			continue ;
		else
			ft_strjoin_char(normalized, src[var.idx]);
	}
	ft_strjoin_char(normalized, SPERATOR);
}
