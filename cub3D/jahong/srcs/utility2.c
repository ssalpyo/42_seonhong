/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:41:32 by jayi              #+#    #+#             */
/*   Updated: 2022/02/07 19:18:46 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utility.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_isalpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_strcmp(char *dst, char *src)
{
	while (*dst != '\0' && *dst == *src)
	{
		dst++;
		src++;
	}
	return (*dst - *src);
}

int	ft_isupper(char symbol)
{
	return ('A' <= symbol && symbol <= 'Z');
}

int	ft_isspace(char symbol)
{
	if (symbol == ' ')
		return (1);
	else
		return (0);
}

void	check_file(char *filename, int flag)
{
	int	fd;

	fd = open(filename, flag);
	if (fd == -1)
		ft_exit(0, "not exists file\n");
	close(fd);
}
