/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:31:43 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/03 13:44:37 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_info *info, int flag)
{
	int		i;
	int		temp;

	i = 0;
	temp = info->a[0];
	while (i < info->a_top)
	{
		info->a[i] = info->a[i + 1];
		++i;
	}
	info->a[info->a_top] = temp;
	if (flag)
		write(1, "rra\n", 4);
}

void		rrb(t_info *info, int flag)
{
	int		i;
	int		temp;

	i = 0;
	temp = info->b[0];
	while (i < info->b_top)
	{
		info->b[i] = info->b[i + 1];
		++i;
	}
	info->b[info->b_top] = temp;
	if (flag)
		write(1, "rrb\n", 4);
}

void		rrr(t_info *info)
{
	rra(info, 0);
	rrb(info, 0);
	write(1, "rrr\n", 4);
}
