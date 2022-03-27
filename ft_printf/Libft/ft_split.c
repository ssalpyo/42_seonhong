/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:07:41 by seonhong          #+#    #+#             */
/*   Updated: 2020/12/30 17:14:37 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *str, char c)
{
	size_t count;

	count = 0;
	if (*str == '\0')
		return (0);
	if (*str++ != c)
		++count;
	while (*str)
	{
		if (*str != c && *(str - 1) == c)
			++count;
		++str;
	}
	return (count);
}

static char		**ft_free_strs(char **str, size_t i)
{
	while (i)
		free(str[--i]);
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	char	*str;
	size_t	size;
	size_t	i;

	if (!s || !(result = ft_calloc(ft_word_count(s, c) + 1, sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str = (char *)s;
			while (*s && *s != c)
				++s;
			size = s - str + 1;
			if ((result[i] = ft_calloc(size, sizeof(char))) == NULL)
				return (ft_free_strs(result, i));
			ft_strlcpy(result[i++], str, size);
		}
		else
			++s;
	}
	return (result);
}
