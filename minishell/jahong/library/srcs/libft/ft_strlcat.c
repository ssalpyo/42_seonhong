/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:18:31 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/07 21:56:09 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dest && i < size)
	{
		++dest;
		++i;
	}
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		++i;
	}
	if (i < size)
		*dest = '\0';
	while (*src++)
		++i;
	return (i);
}
