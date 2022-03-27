/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:46:04 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 22:25:48 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_format(char format, t_spec spec, va_list ap)
{
	if (format == 'c')
		return (ft_print_c(spec, ap));
	else if (format == 's')
		return (ft_print_s(spec, ap));
	else if (format == 'p')
		return (ft_print_p(spec, ap));
	else if (format == 'd')
		return (ft_print_d(spec, ap));
	else if (format == 'i')
		return (ft_print_d(spec, ap));
	else if (format == 'u')
		return (ft_print_u(spec, ap));
	else if (format == 'x')
		return (ft_print_x(spec, ap));
	else if (format == 'X')
		return (ft_print_upper_x(spec, ap));
	else if (format == '%')
		return (ft_print_percent(spec));
	return (0);
}

static char		*pars_format(const char *str)
{
	while (*str)
	{
		if (*str == 'c' ||
		*str == 's' ||
		*str == 'p' ||
		*str == 'd' ||
		*str == 'i' ||
		*str == 'u' ||
		*str == 'x' ||
		*str == 'X' ||
		*str == '%')
			return ((char *)str);
		++str;
	}
	return (NULL);
}

static int		ft_print(const char *str, va_list ap)
{
	char		*format;
	t_spec		spec;

	if ((format = pars_format(str)) == NULL)
		return (-1);
	spec = pars_spec(str, format - str, *format, ap);
	if ((spec.errno) != 0)
		return (-1);
	return (ft_print_format(*format, spec, ap));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*find;
	int			result;
	int			len_print;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	result = 0;
	while ((find = ft_strchr(format, '%')))
	{
		result += write(1, format, find - format);
		if ((len_print = ft_print(find + 1, ap)) < 0)
			return (-1);
		result += len_print;
		format = pars_format(find + 1) + 1;
	}
	result += write(1, format, ft_strlen(format));
	va_end(ap);
	return (result);
}
