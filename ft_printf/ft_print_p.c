/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:51:21 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/10 01:17:37 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_p(t_spec spec, va_list ap)
{
	char		*address;
	void		*p;
	int			result;

	if (spec.precision > 0)
		return (-1);
	p = (void *)va_arg(ap, void *);
	if ((address = ft_getaddress_p(p, &spec)) == NULL)
		return (-1);
	result = write(1, address, spec.width);
	free(address);
	return (result);
}

char			*ft_getaddress_p(void *p, t_spec *spec)
{
	long long	address;
	char		*result;
	int			size;
	int			temp;

	size = ft_getaddress_size_p((long long)p, *spec);
	if (size > spec->width)
		spec->width = size;
	if ((result = malloc(sizeof(char) * (spec->width))) == NULL)
		return (NULL);
	ft_memset(result, ' ', spec->width);
	address = (long long)p;
	if (spec->minus)
		temp = size - 1;
	else
		temp = spec->width - 1;
	while (size-- - 2)
	{
		*(result + temp--) = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	*(result + temp) = 'x';
	*(result + temp - 1) = '0';
	return (result);
}

int				ft_getaddress_size_p(long long address, t_spec spec)
{
	int			result;

	if (spec.precision == 0 && address == 0)
		return (2);
	result = 3;
	while (address >= 16)
	{
		address /= 16;
		++result;
	}
	return (result);
}
