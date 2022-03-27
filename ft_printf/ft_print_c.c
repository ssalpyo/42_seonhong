/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:05:36 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/10 00:47:00 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_c(t_spec spec, va_list ap)
{
	int		result;
	char	c;
	char	*buff;

	c = (char)va_arg(ap, int);
	if (spec.width <= 0)
		spec.width = 1;
	if ((buff = malloc(sizeof(char) * (spec.width))) == NULL)
		return (-1);
	ft_memset(buff, ' ', spec.width);
	if (spec.minus)
		*buff = c;
	else
		*(buff + spec.width - 1) = c;
	result = write(1, buff, spec.width);
	free(buff);
	return (result);
}
