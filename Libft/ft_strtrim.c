/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:11:52 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/07 21:58:26 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	char const	*save;
	size_t		len;

	if (s1 == NULL)
		return (NULL);
	while (*s1 && ft_is_set(*s1, set))
		++s1;
	len = ft_strlen(s1);
	save = s1 + len - 1;
	while (s1 <= save && ft_is_set(*save, set))
	{
		--save;
		--len;
	}
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len + 1);
	return (result);
}
