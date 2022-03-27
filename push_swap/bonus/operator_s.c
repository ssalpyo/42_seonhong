/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:31:51 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/07 22:36:33 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		sa(t_info *info)
{
	int temp;

	if (info->a_top >= 1)
	{
		temp = info->a[info->a_top];
		info->a[info->a_top] = info->a[info->a_top - 1];
		info->a[info->a_top - 1] = temp;
	}
}

void		sb(t_info *info)
{
	int		temp;

	if (info->a_top >= 1)
	{
		temp = info->b[info->b_top];
		info->b[info->b_top] = info->b[info->b_top - 1];
		info->b[info->b_top - 1] = temp;
	}
}

void		ss(t_info *info)
{
	sa(info);
	sb(info);
}
