/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:03:25 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 17:17:42 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_bufsize_d(t_spec *spec, int length, int arg, int sign)
{
	int			bufsize;

	if ((spec->width <= 0 && !spec->precision && !arg && sign) ||
	(spec->width == -1 && spec->precision == -1))
		bufsize = length + sign;
	else if (spec->width > spec->precision)
	{
		if (spec->width > length + sign)
			bufsize = spec->width;
		else
			bufsize = length + sign;
	}
	else
	{
		if (spec->precision > length)
			bufsize = spec->precision + sign;
		else
			bufsize = length + sign;
	}
	return (bufsize);
}

int				ft_print_d(t_spec spec, va_list ap)
{
	int			arg;
	int			length;
	int			sign;
	int			bufsize;
	char		*buff;

	arg = (int)va_arg(ap, int);
	length = ft_get_numsize_d(arg, spec);
	sign = 0;
	if (arg < 0)
		sign = 1;
	if (spec.width <= 0 && !spec.precision && !arg && !sign)
		return (0);
	bufsize = ft_get_bufsize_d(&spec, length, arg, sign);
	if ((buff = ft_setbuf_d(arg, bufsize, length, spec)) == NULL)
		return (-1);
	length = write(1, buff, bufsize);
	free(buff);
	return (length);
}

int				ft_get_numsize_d(long long num, t_spec spec)
{
	int			result;
	long long	copy;

	if (num == 0 && spec.precision == 0)
		return (0);
	result = 1;
	if (num < 0)
		copy = num * -1;
	else
		copy = num;
	while (copy >= 10)
	{
		copy /= 10;
		++result;
	}
	return (result);
}
