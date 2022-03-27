/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:52:25 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/07 21:55:27 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s);
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s, len + 1);
	return (result);
}
