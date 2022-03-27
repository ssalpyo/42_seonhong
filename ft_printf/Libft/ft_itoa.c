/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:15:27 by seonhong          #+#    #+#             */
/*   Updated: 2020/12/29 22:23:24 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_len(int n)
{
	return (n == 0 ? 0 : 1 + ft_check_len(n / 10));
}

char		*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	unsigned int	num;

	len = ft_check_len(n / 10) + 1;
	if (n < 0)
	{
		num = -n;
		++len;
	}
	else
		num = n;
	if ((result = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	if (n < 0)
		*result = '-';
	*(result + --len) = (num % 10) + '0';
	while (num /= 10)
		*(result + --len) = (num % 10) + '0';
	return (result);
}
