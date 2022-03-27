/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 01:25:12 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 19:58:50 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_percent(t_spec spec)
{
	char		*buff;
	int			length;

	if (spec.width <= 1)
		return (write(1, "%", 1));
	if ((buff = malloc(sizeof(char) * spec.width)) == NULL)
		return (-1);
	if (spec.zero && !spec.minus)
		ft_memset(buff, '0', spec.width);
	else
		ft_memset(buff, ' ', spec.width);
	if (spec.minus)
		*buff = '%';
	else
		*(buff + spec.width - 1) = '%';
	length = write(1, buff, spec.width);
	free(buff);
	return (length);
}
