/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:41:32 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:52:16 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utility.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	copy_data(int *dest, int *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < size)
	{
		dest[idx] = src[idx];
		++idx;
	}
}

int	exit_game(void)
{
	exit(0);
	return (0);
}

void	clear_data(int *data, int width, int height)
{
	const int	max_idx = width * height;
	int			idx;

	idx = 0;
	while (idx < max_idx)
	{
		data[idx] = 0x000000;
		++idx;
	}
}

void	ft_exit(int no, const char *err_msg)
{
	if (DEBUG == 1)
	{
		printf("%s\n", err_msg);
	}
	printf(ERROR_MSG);
	exit(no);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
