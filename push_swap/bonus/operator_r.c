/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:31:39 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/07 22:36:10 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ra(t_info *info)
{
	int		i;
	int		temp;

	i = info->a_top;
	if (i != -1)
	{
		temp = info->a[info->a_top];
		while (i > 0)
		{
			info->a[i] = info->a[i - 1];
			--i;
		}
		info->a[0] = temp;
	}
}

void		rb(t_info *info)
{
	int		i;
	int		temp;

	i = info->b_top;
	if (i != -1)
	{
		temp = info->b[info->b_top];
		while (i > 0)
		{
			info->b[i] = info->b[i - 1];
			--i;
		}
		info->b[0] = temp;
	}
}

void		rr(t_info *info)
{
	ra(info);
	rb(info);
}
