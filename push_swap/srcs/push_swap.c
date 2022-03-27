/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:49:11 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/04 18:39:35 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(int argc, char *argv[])
{
	t_info	info;

	setting_num(&info, argc, argv);
	if (!check_sort_a(&info, info.size))
	{
		if (info.a_top == 2)
			three_arg(&info);
		else if (info.a_top == 4)
			five_arg(&info);
		else
			a_to_b(&info, info.size);
	}
	free(info.a);
	free(info.b);
}
