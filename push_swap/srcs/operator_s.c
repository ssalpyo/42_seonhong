/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:31:51 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/03 13:06:40 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_info *info, int flag)
{
	int temp;

	if (info->a_top >= 1)
	{
		temp = info->a[info->a_top];
		info->a[info->a_top] = info->a[info->a_top - 1];
		info->a[info->a_top - 1] = temp;
	}
	if (flag)
		write(1, "sa\n", 3);
}

void		sb(t_info *info, int flag)
{
	int		temp;

	if (info->a_top >= 1)
	{
		temp = info->b[info->b_top];
		info->b[info->b_top] = info->b[info->b_top - 1];
		info->b[info->b_top - 1] = temp;
	}
	if (flag)
		write(1, "sb\n", 3);
}

void		ss(t_info *info)
{
	sa(info, 0);
	sb(info, 0);
	write(1, "ss\n", 3);
}
