/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:25:20 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/04 19:32:54 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_sort_a(t_info *info, int size)
{
	int		i;

	i = info->a_top - size + 1;
	while (i < info->a_top)
	{
		if (info->a[i] < info->a[i + 1])
			return (0);
		++i;
	}
	return (1);
}

int			check_sort_b(t_info *info, int size)
{
	int		i;

	i = info->b_top - size + 1;
	while (i < info->b_top)
	{
		if (info->b[i] > info->b[i + 1])
			return (0);
		++i;
	}
	return (1);
}
