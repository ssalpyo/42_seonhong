/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbuf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:42:58 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 18:07:00 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_setbuf_d(long long arg, int bufsize, int length, t_spec spec)
{
	t_box	box;

	if ((box.buff = malloc(sizeof(char) * bufsize)) == NULL)
		return (NULL);
	box.start = box.buff;
	ft_memset(box.buff, ' ', bufsize);
	if (spec.zero && !spec.minus && spec.precision == -1)
		ft_memset(box.buff, '0', bufsize);
	box.temp = spec.precision;
	if (spec.minus)
	{
		ft_setsign_d(arg, &(box.buff), spec, box.start);
		while ((box.temp)-- > length)
			*(box.buff++) = '0';
		ft_setnum_d(arg, box.buff + length - 1, spec);
	}
	else
	{
		ft_setnum_d(arg, box.buff + bufsize - 1, spec);
		box.buff = box.buff + bufsize - 1 - length;
		while ((box.temp)-- > length)
			*(box.buff--) = '0';
		ft_setsign_d(arg, &(box.buff), spec, box.start);
	}
	return (box.start);
}

void		ft_setsign_d(long long num, char **buff, t_spec spec, char *start)
{
	if (spec.zero && !spec.minus && spec.precision == -1)
		*buff = start;
	if (num < 0)
	{
		**buff = '-';
		++(*buff);
	}
}

void		ft_setnum_d(long long num, char *tail, t_spec spec)
{
	if (spec.precision == 0 && num == 0)
		return ;
	if (num < 0)
		num *= -1;
	while (num >= 10)
	{
		*tail-- = num % 10 + '0';
		num /= 10;
	}
	*tail = num % 10 + '0';
}
