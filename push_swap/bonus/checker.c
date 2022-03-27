/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:34:03 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/07 22:39:24 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

static int		operation(t_info *info, char *line)
{
	if (ft_strcmp("sa", line) == 0)
		sa(info);
	else if (ft_strcmp("sb", line) == 0)
		sb(info);
	else if (ft_strcmp("ss", line) == 0)
		ss(info);
	else if (ft_strcmp("pa", line) == 0)
		pa(info);
	else if (ft_strcmp("pb", line) == 0)
		pb(info);
	else if (ft_strcmp("ra", line) == 0)
		ra(info);
	else if (ft_strcmp("rb", line) == 0)
		rb(info);
	else if (ft_strcmp("rr", line) == 0)
		rr(info);
	else if (ft_strcmp("rra", line) == 0)
		rra(info);
	else if (ft_strcmp("rrb", line) == 0)
		rrb(info);
	else if (ft_strcmp("rrr", line) == 0)
		rrr(info);
	else
		return (0);
	return (1);
}

static void		start_sort(t_info *info)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (!operation(info, line))
		{
			write(1, "Error\n", 6);
			free(line);
			exit(1);
		}
		free(line);
	}
	free(line);
}

static int		check_sort_a(t_info *info, int size)
{
	int i;

	i = info->a_top - size + 1;
	while (i < info->a_top)
	{
		if (info->a[i] < info->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void			checker(int argc, char *argv[])
{
	t_info	info;

	setting_num(&info, argc, argv);
	start_sort(&info);
	if (info.b_top == -1 && check_sort_a(&info, info.size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(info.a);
	free(info.b);
}
