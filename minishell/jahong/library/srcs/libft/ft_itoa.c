/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:15:27 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/07 22:54:19 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_len(long long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		++len;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		++len;
	}
	++len;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		len;
	long long	num;

	num = n;
	len = ft_check_len(num);
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		*result = '-';
	}
	while (num / 10 > 0)
	{
		*(result + --len) = (num % 10) + '0';
		num /= 10;
	}
	*(result + --len) = (num % 10) + '0';
	return (result);
}
