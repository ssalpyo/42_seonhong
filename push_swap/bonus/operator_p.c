/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:31:32 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/19 17:37:52 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		pa(t_info *info)
{
	if (info->b_top >= 0)
	{
		info->a_top++;
		info->a[info->a_top] = info->b[info->b_top];
		info->b_top--;
	}
}

void		pb(t_info *info)
{
	if (info->a_top >= 0)
	{
		info->b_top++;
		info->b[info->b_top] = info->a[info->a_top];
		info->a_top--;
	}
}
