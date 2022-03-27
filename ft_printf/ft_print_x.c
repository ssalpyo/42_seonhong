/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:02:15 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 19:59:45 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_x(t_spec spec, va_list ap)
{
	unsigned int	arg;
	t_size			size;
	char			*buff;
	int				bufsize;

	arg = (unsigned int)va_arg(ap, unsigned int);
	size = ft_get_numsize_x(arg, spec);
	if (spec.width <= 0 && !spec.precision && !arg)
		return (0);
	bufsize = ft_get_bufsize_x(spec, size.length);
	if ((buff = ft_setbuf_x(arg, bufsize, 0, spec)) == NULL)
		return (-1);
	size.length = write(1, buff, bufsize);
	free(buff);
	return (size.length);
}

int			ft_print_upper_x(t_spec spec, va_list ap)
{
	unsigned int	arg;
	t_size			size;
	char			*buff;
	int				bufsize;

	arg = (unsigned int)va_arg(ap, unsigned int);
	size = ft_get_numsize_x(arg, spec);
	if (spec.width <= 0 && !spec.precision && !arg)
		return (0);
	bufsize = ft_get_bufsize_x(spec, size.length);
	if ((buff = ft_setbuf_x(arg, bufsize, 1, spec)) == NULL)
		return (-1);
	size.length = write(1, buff, bufsize);
	free(buff);
	return (size.length);
}

t_size		ft_get_numsize_x(long long num, t_spec spec)
{
	t_size			size;
	long long		copy;

	size = init_size();
	if (num == 0)
		size.is_zero_num = 1;
	if (spec.precision == 0)
		size.is_zero_prec = 1;
	if (size.is_zero_num && size.is_zero_prec)
		return (size);
	if (num < 0)
		copy = num * -1;
	else
		copy = num;
	while (copy >= 16)
	{
		copy /= 16;
		++size.length;
	}
	return (size);
}

t_size		init_size(void)
{
	t_size		size;

	size.is_zero_num = 0;
	size.is_zero_prec = 0;
	size.length = 1;
	return (size);
}

int			ft_get_bufsize_x(t_spec spec, int length)
{
	int			bufsize;

	if (spec.width == -1 && spec.precision == -1)
		bufsize = length;
	else if (spec.width > spec.precision)
	{
		if (spec.width > length)
			bufsize = spec.width;
		else
			bufsize = length;
	}
	else
	{
		if (spec.precision > length)
			bufsize = spec.precision;
		else
			bufsize = length;
	}
	return (bufsize);
}
