/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:02:27 by seonhong          #+#    #+#             */
/*   Updated: 2020/12/29 22:31:31 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *result;

	if ((result = malloc(count * size)) == NULL)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
