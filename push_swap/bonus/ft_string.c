/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:28:01 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/07 22:35:34 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		len;

	if (src == NULL)
		return (0);
	len = 0;
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

int			ft_atoi(const char *str, int *result)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + (*str++ - '0');
	if (*str != '\0' || num > 2147483647 || num < -2147483648)
		return (0);
	*result = num * sign;
	return (1);
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
