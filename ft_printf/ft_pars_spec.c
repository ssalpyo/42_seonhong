/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:08:11 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 22:40:37 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec		pars_spec(const char *str, int length, char format, va_list ap)
{
	t_spec	spec;

	spec = init_spec();
	if (length == 0)
		return (spec);
	while (pars_flag(*str, &spec))
		++str;
	pars_width(&str, &spec, ap);
	pars_precision(&str, &spec, ap);
	if (*str != format)
		spec.errno = -1;
	return (spec);
}

t_spec		init_spec(void)
{
	t_spec	spec;

	spec.minus = 0;
	spec.zero = 0;
	spec.width = -1;
	spec.precision = -1;
	spec.errno = 0;
	return (spec);
}

int			pars_flag(int c, t_spec *spec)
{
	if (c == '-')
		spec->minus = 1;
	else if (c == '0')
		spec->zero = 1;
	else
		return (0);
	return (1);
}

void		pars_width(const char **str, t_spec *spec, va_list ap)
{
	if (**str == '*')
	{
		spec->width = (int)va_arg(ap, int);
		if (spec->width < 0)
		{
			spec->minus = 1;
			spec->width *= -1;
		}
		++(*str);
	}
	else if (ft_isdigit(**str))
	{
		spec->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			++(*str);
	}
}

void		pars_precision(const char **str, t_spec *spec, va_list ap)
{
	if (**str != '.')
		return ;
	if (*(++(*str)) == '*')
	{
		spec->precision = (int)va_arg(ap, int);
		if (spec->precision < 0)
			spec->precision = -1;
		++(*str);
	}
	else if (ft_isdigit(**str))
	{
		spec->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			++(*str);
	}
	else
		spec->precision = 0;
}
