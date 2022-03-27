/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:00:55 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/04 16:52:33 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				*copy_arr(t_info *info, int size, int flag)
{
	int		*arr;
	int		i;

	if ((arr = (int *)malloc(sizeof(int) * size)) == NULL)
		exit(1);
	i = -1;
	if (flag == 1)
	{
		while (++i < size)
			arr[i] = info->a[info->a_top - i];
	}
	else
	{
		while (++i < size)
			arr[i] = info->b[info->b_top - i];
	}
	return (arr);
}

t_pivot			get_pivot(t_info *info, int size, int flag)
{
	t_pivot		pivot;
	int			*arr;
	int			term;

	arr = copy_arr(info, size, flag);
	ft_sort(arr, size);
	term = size / 3;
	if (size % 3 == 2)
		term++;
	if (flag == 1)
	{
		pivot.p1 = arr[size - term];
		pivot.p2 = arr[size - term * 2];
	}
	else
	{
		pivot.p1 = arr[term * 2 - 1];
		pivot.p2 = arr[term - 1];
	}
	free(arr);
	return (pivot);
}
