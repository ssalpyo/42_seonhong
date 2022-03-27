/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:52:58 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/07 22:00:32 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	len_s;

	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s == NULL || len == 0)
		return (result);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (result);
	if (start + len > len_s)
		len = len_s - start;
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
