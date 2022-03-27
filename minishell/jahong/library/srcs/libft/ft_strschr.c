/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:14:04 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/30 13:20:39 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strschr(char **s, int c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
