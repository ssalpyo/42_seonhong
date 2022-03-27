/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbuf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:41:20 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 19:52:56 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_setbuf_x(long long arg, int bufsize, int isupper, t_spec spec)
{
	t_box	box;

	if ((box.buff = malloc(sizeof(char) * bufsize)) == NULL)
		return (NULL);
	box.size = ft_get_numsize_x(arg, spec);
	box.start = box.buff;
	ft_memset(box.buff, ' ', bufsize);
	if (spec.zero && !spec.minus && spec.precision == -1)
		ft_memset(box.buff, '0', bufsize);
	box.temp = spec.precision;
	if (spec.minus)
	{
		while ((box.temp)-- > box.size.length)
			*(box.buff++) = '0';
		ft_setnum_x(arg, box.buff + box.size.length - 1, isupper, spec);
	}
	else
	{
		ft_setnum_x(arg, box.buff + bufsize - 1, isupper, spec);
		box.buff = box.buff + bufsize - 1 - box.size.length;
		while ((box.temp)-- > box.size.length)
			*(box.buff--) = '0';
	}
	return (box.start);
}

void		ft_setnum_x(long long num, char *tail, int isupper, t_spec spec)
{
	if (spec.precision == 0 && num == 0)
		return ;
	if (num < 0)
		num *= -1;
	while (num >= 16)
	{
		if (!isupper)
			*tail-- = "0123456789abcdef"[num % 16];
		else
			*tail-- = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	if (!isupper)
		*tail = "0123456789abcdef"[num % 16];
	else
		*tail = "0123456789ABCDEF"[num % 16];
}
