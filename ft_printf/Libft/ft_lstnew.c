/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:34:02 by seonhong          #+#    #+#             */
/*   Updated: 2020/12/29 22:23:56 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *result;

	if ((result = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	result->content = content;
	result->next = 0;
	return (result);
}
