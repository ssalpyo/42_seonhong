/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:07:41 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/07 22:37:04 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_alloc(void **src, void *des)
{
	*src = des;
	return (src);
}

static size_t	ft_word_count(char const *str, char c)
{
	size_t	count;

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

static char	*ft_getword(char const *s, char c, size_t *offset)
{
	char const	*start;
	char const	*last;
	char		*result;

	while (*(s + *offset) != '\0' && *(s + *offset) == c)
		++(*offset);
	start = s + *offset;
	while (*(s + *offset) != '\0' && *(s + *offset) != c)
		++(*offset);
	last = s + *offset;
	result = ft_calloc(last - start + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, start, last - start + 1);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	size_t	count;
	size_t	index;
	size_t	offset;

	if (s == NULL)
		return (NULL);
	count = ft_word_count(s, c);
	if (ft_alloc((void **)&strs, ft_calloc(count + 1, sizeof(char *))) == NULL)
		return (NULL);
	index = 0;
	offset = 0;
	while (index < count)
	{
		if (ft_alloc((void **)&str, ft_getword(s, c, &offset)) == NULL)
		{
			while (index > 0)
				free(*(strs + --index));
			free(strs);
			return (NULL);
		}
		*(strs + index++) = str;
	}
	return (strs);
}
