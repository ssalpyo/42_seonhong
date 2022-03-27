/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:40:37 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:44:46 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "define.h"
#include "utility.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

static void	check_dot_cub(char *filename)
{
	int	i;

	i = 0;
	while (filename[i] != '\0')
	{
		if (filename[i + 0] == '.' \
		&& filename[i + 1] == 'c' \
		&& filename[i + 2] == 'u' \
		&& filename[i + 3] == 'b' \
		&& filename[i + 4] == '\0')
			return ;
		i++;
	}
	ft_exit(0, "not .cub file\n");
}

static void	init_cub(void)
{
	int	i;

	get_g()->str_map = NULL;
	get_g()->map_y = 0;
	get_g()->map_x = 0;
	i = 0;
	while (i < 6)
		get_g()->op_flags[i++] = 0;
}

void	parse_cub(char *filename)
{
	const int	fd = open(filename, O_RDONLY);

	check_dot_cub(filename);
	init_cub();
	if (fd == -1)
		ft_exit(0, "file not open\n");
	read_cub(fd);
	check_cub();
	allocate_map();
	parse_map();
	check_map(get_g()->pl_s_x, get_g()->pl_s_y);
	if (get_g()->player_flag != 1)
		ft_exit(0, "invalid player count\n");
	rewind_map();
}

void	check_map(int x, int y)
{
	if (get_g()->w_map[x][y] == 1 || get_g()->w_map[x][y] == CHECKED_MAP)
		return ;
	if (x == 0 || x == get_g()->map_x - 1 || y == 0 || y == get_g()->map_y - 1)
		ft_exit(0, "invalid map\n");
	if (get_g()->w_map[x][y] == 0)
		get_g()->w_map[x][y] = CHECKED_MAP;
	check_map(x, y - 1);
	check_map(x, y + 1);
	check_map(x + 1, y);
	check_map(x - 1, y);
}

void	rewind_map(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < get_g()->map_y)
	{
		x = 0;
		while (x < get_g()->map_x)
		{
			if (get_g()->w_map[x][y] == CHECKED_MAP)
				get_g()->w_map[x][y] = 0;
			x++;
		}
		y++;
	}
}
