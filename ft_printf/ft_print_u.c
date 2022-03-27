/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:35:35 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 18:48:42 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_bufsize_u(t_spec *spec, int length)
{
	int				bufsize;

	if (spec->width == -1 && spec->precision == -1)
		bufsize = length;
	else if (spec->width > spec->precision)
	{
		if (spec->width > length)
			bufsize = spec->width;
		else
			bufsize = length;
	}
	else
	{
		if (spec->precision > length)
			bufsize = spec->precision;
		else
			bufsize = length;
	}
	return (bufsize);
}

int				ft_print_u(t_spec spec, va_list ap)
{
	unsigned int	arg;
	int				bufsize;
	int				length;
	char			*buff;

	arg = (unsigned int)va_arg(ap, unsigned int);
	length = ft_get_numsize_d(arg, spec);
	if (spec.width <= 0 && !spec.precision && !arg)
		return (0);
	bufsize = ft_get_bufsize_u(&spec, length);
	if ((buff = ft_setbuf_d(arg, bufsize, length, spec)) == NULL)
		return (-1);
	length = write(1, buff, bufsize);
	free(buff);
	return (length);
}
