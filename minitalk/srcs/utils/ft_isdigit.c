/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonghong@student.42seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:07:08 by seonhong          #+#    #+#             */
/*   Updated: 2021/09/26 16:09:43 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isdigit_str(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		if (!(ft_isdigit(s[i++])))
			return (0);
	return (1);
}
