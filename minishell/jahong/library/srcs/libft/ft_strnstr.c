/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:12:21 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/07 21:57:49 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	len_find;

	if (*to_find == '\0')
		return ((char *)str);
	len_find = ft_strlen(to_find);
	while (*str && len-- >= len_find)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, len_find) == 0)
			return ((char *)str);
		++str;
	}
	return (NULL);
}
