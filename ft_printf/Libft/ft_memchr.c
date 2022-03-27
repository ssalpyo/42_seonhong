/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:07:17 by seonhong          #+#    #+#             */
/*   Updated: 2020/12/30 17:13:43 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *temp;

	temp = s;
	while (n--)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		++temp;
	}
	return (NULL);
}
