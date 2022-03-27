/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:31:54 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/07 21:56:34 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (src == NULL)
		return (0);
	if (size > 0)
	{
		while (*src && len < size - 1)
		{
			*dest++ = *src++;
			++len;
		}
		*dest = '\0';
	}
	while (*src)
	{
		++len;
		++src;
	}
	return (len);
}
