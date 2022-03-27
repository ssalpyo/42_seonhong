/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:52:25 by seonhong          #+#    #+#             */
/*   Updated: 2020/12/29 22:24:56 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s);
	if ((result = (char *)ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	ft_strlcpy(result, s, len + 1);
	return (result);
}
