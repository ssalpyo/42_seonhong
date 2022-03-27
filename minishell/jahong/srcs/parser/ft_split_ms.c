/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:08:11 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/24 10:49:06 by jayi             ###   ########.fr       */
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

static int	each_len(char const *s, char c, int start)
{
	int	len;
	int	flag;

	len = 0;
	flag = 0;
	while (s[start + len] != '\0')
	{
		if (is_valid_quote(s[start + len], FALSE))
			flag = !flag;
		if (flag == 0 && s[start + len] == c)
			return (len);
		len++;
	}
	return (len);
}

static int	find_start(char const *s, char c, int i)
{
	int	flag;

	flag = 0;
	while (s[i] != '\0' && (s[i] == c || flag == 1))
	{
		if (is_valid_quote(s[i], FALSE))
			flag = !flag;
		i++;
	}
	return (i);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = -1;
	count = 0;
	flag = 0;
	while (s[++i])
	{
		if (is_valid_quote(s[i], FALSE))
			flag = !flag;
		if (flag == 0 && s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
	}
	return (count);
}

typedef struct s_split_var{
	int	i;
	int	word_len;
	int	words_count;
}	t_split_var;

char	**ft_split_ms(char const *s, char c)
{
	char			**array;
	int				start;
	t_split_var		v;

	v = (t_split_var){-1, 0, 0};
	v.words_count = count_words(s, c);
	array = (char **)malloc((v.words_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	is_valid_quote(0, TRUE);
	start = find_start(s, c, 0);
	while (++v.i < v.words_count)
	{
		v.word_len = each_len(s, c, start);
		array[v.i] = malloc((v.word_len + 1) * sizeof(char));
		if (!array[v.i])
			return (NULL);
		ft_strlcpy(array[v.i], s + start, v.word_len + 1);
		start = find_start(s, c, start + v.word_len);
	}
	array[v.i] = (char *) 0;
	return (array);
}
