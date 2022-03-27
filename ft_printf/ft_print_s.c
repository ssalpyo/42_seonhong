/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:04 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 22:24:18 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_bufsize_s(t_spec *spec, char *str)
{
	int		len_str;
	int		len_buff;

	len_str = ft_strlen(str);
	if (spec->precision < 0 && spec->width < len_str)
		len_buff = len_str;
	else if (spec->precision < 0)
		len_buff = spec->width;
	else
	{
		if (spec->width > len_str)
			len_str = spec->width;
		if (spec->width >= spec->precision)
			len_buff = spec->width;
		else
		{
			if (spec->precision > len_str)
				len_buff = len_str;
			else
				len_buff = spec->precision;
		}
	}
	return (len_buff);
}

int				ft_print_s(t_spec spec, va_list ap)
{
	char	*str;
	char	*buff;
	int		len_buff;
	int		result;

	str = (char *)va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len_buff = ft_get_bufsize_s(&spec, str);
	if ((buff = malloc(sizeof(char) * len_buff)) == NULL)
		return (-1);
	ft_bufset_s(spec, len_buff, str, buff);
	result = write(1, buff, len_buff);
	free(buff);
	return (result);
}

void			ft_bufset_s(t_spec spec, int len_buff, char *str, char *buff)
{
	int		len_str;

	len_str = ft_strlen(str);
	if (spec.zero && !spec.minus && spec.precision == -1)
		ft_memset(buff, '0', len_buff);
	else
		ft_memset(buff, ' ', len_buff);
	if (spec.precision != -1 && len_str > spec.precision)
		len_str = spec.precision;
	if (spec.minus)
		ft_memcpy(buff, str, len_str);
	else
		ft_memcpy(buff + len_buff - len_str, str, len_str);
}
