/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:06:46 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/04 17:04:38 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = c;
	return (s);
}

static void		*ft_calloc(size_t count, size_t size)
{
	void *result;

	if ((result = malloc(count * size)) == NULL)
		return (NULL);
	ft_memset(result, 0, count * size);
	return (result);
}

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

char			**ft_free_strs(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
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
		exit(1);
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
				return (ft_free_strs(result));
			ft_strlcpy(result[i++], str, size);
		}
		else
			++s;
	}
	return (result);
}
