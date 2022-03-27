/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_to_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:17:01 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/04 19:57:56 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count		init_count(void)
{
	t_count		count;

	count.ra = 0;
	count.rb = 0;
	count.pa = 0;
	count.pb = 0;
	return (count);
}

void		a_to_b(t_info *info, int size)
{
	t_count		count;
	t_pivot		pivot;
	int			i;

	count = init_count();
	if (check_sort_a(info, size))
		return ;
	if (size <= 4)
	{
		small_sort_a(info, size);
		return ;
	}
	pivot = get_pivot(info, size, 1);
	a_to_b_util(info, &count, pivot, size);
	i = -1;
	while (++i < count.ra)
		rrr(info);
	a_to_b(info, count.ra);
	b_to_a(info, count.rb);
	b_to_a(info, count.pb - count.rb);
}

void		b_to_a(t_info *info, int size)
{
	t_count		count;
	t_pivot		pivot;
	int			i;

	count = init_count();
	if (check_sort_b(info, size))
	{
		while (size--)
			pa(info);
		return ;
	}
	if (size <= 3)
	{
		small_sort_b(info, size);
		return ;
	}
	pivot = get_pivot(info, size, 0);
	b_to_a_util(info, &count, pivot, size);
	a_to_b(info, count.pa - count.ra);
	i = -1;
	while (++i < count.ra)
		rrr(info);
	a_to_b(info, count.rb);
	b_to_a(info, count.ra);
}

void		a_to_b_util(t_info *info, t_count *count, t_pivot pivot, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (info->a[info->a_top] >= pivot.p1)
		{
			ra(info, 1);
			count->ra++;
		}
		else
		{
			pb(info);
			count->pb++;
			if (info->b[info->b_top] >= pivot.p2)
			{
				rb(info, 1);
				count->rb++;
			}
		}
		++i;
	}
}

void		b_to_a_util(t_info *info, t_count *count, t_pivot pivot, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (info->b[info->b_top] <= pivot.p2)
		{
			rb(info, 1);
			count->rb++;
		}
		else
		{
			pa(info);
			count->pa++;
			if (info->a[info->a_top] <= pivot.p1)
			{
				ra(info, 1);
				count->ra++;
			}
		}
		++i;
	}
}
