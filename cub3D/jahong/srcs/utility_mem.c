/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:37:54 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 22:44:12 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility_mem.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cur_dst;
	const char	*cur_src;
	const char	*end_src;

	if (dst == src)
	{
		return (NULL);
	}
	cur_dst = dst;
	cur_src = src;
	end_src = cur_src + n;
	while (cur_src != end_src)
	{
		*cur_dst = *cur_src;
		++cur_src;
		++cur_dst;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cur_dst;
	const char	*cur_src;
	const char	*start_src;

	cur_dst = dst;
	cur_src = src;
	if (cur_dst <= cur_src)
	{
		ft_memcpy(cur_dst, cur_src, len);
	}
	else
	{
		start_src = src;
		cur_dst = dst + len - 1;
		cur_src = src + len - 1;
		while (cur_src >= start_src)
		{
			*cur_dst = *cur_src;
			--cur_src;
			--cur_dst;
		}
	}
	return (dst);
}

void	*ft_memset(void *byte_str, int ch, size_t len)
{
	char	*idx_byte;
	char	*end_byte;

	idx_byte = byte_str;
	end_byte = byte_str + len;
	while (idx_byte != end_byte)
	{
		*idx_byte = ch;
		++idx_byte;
	}
	return (byte_str);
}
