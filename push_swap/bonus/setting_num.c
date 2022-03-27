/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:30:43 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/07 22:37:11 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	get_numsize(const char *str)
{
	size_t	size;
	int		check;

	size = 0;
	check = 1;
	while (*str)
	{
		if (check && *str != ' ')
		{
			++size;
			check = 0;
		}
		if (*str == ' ')
			check = 1;
		++str;
	}
	if (size == 0)
		print_error();
	return (size);
}

static void	init_info(t_info *info, int size)
{
	info->a = (int *)malloc(sizeof(int) * size);
	info->a_top = -1;
	info->b = (int *)malloc(sizeof(int) * size);
	info->b_top = -1;
	info->size = size;
	if (!info->a || !info->b)
		exit(1);
}

static int	check_duplicate(int *arr, int num, int size)
{
	int		i;

	i = 0;
	while (size > i)
	{
		if (arr[i] == num)
			return (0);
		++i;
	}
	return (1);
}

static void	swap_stack(t_info *info)
{
	int		left;
	int		right;
	int		temp;

	left = 0;
	right = info->a_top;
	while (left < right)
	{
		temp = info->a[left];
		info->a[left] = info->a[right];
		info->a[right] = temp;
		++left;
		--right;
	}
}

void		setting_num(t_info *info, int argc, char *argv[])
{
	int		size;
	int		index;
	int		temp_index;
	char	**temp;

	size = 0;
	index = 1;
	while (argc > index)
		size += get_numsize(argv[index++]);
	init_info(info, size);
	index = 1;
	while (argc > index)
	{
		temp_index = 0;
		temp = ft_split(argv[index++], ' ');
		while (temp[temp_index])
		{
			info->a_top++;
			if (!ft_atoi(temp[temp_index++], &info->a[info->a_top]) ||
				!check_duplicate(info->a, info->a[info->a_top], info->a_top))
				print_error();
		}
		ft_free_strs(temp);
	}
	swap_stack(info);
}
