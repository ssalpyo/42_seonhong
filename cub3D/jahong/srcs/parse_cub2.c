/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:41:08 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:37:05 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "define.h"
#include "utility.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

void	input_player_location(int x, int y, int direction)
{
	get_g()->w_map[x][y] = 0;
	get_g()->pl_s_x = x;
	get_g()->pl_s_y = y;
	get_g()->player_flag++;
	if (direction == 'N')
		get_g()->pl_s_dir = FLAG_MAP_N;
	else if (direction == 'E')
		get_g()->pl_s_dir = FLAG_MAP_E;
	else if (direction == 'W')
		get_g()->pl_s_dir = FLAG_MAP_W;
	else if (direction == 'S')
		get_g()->pl_s_dir = FLAG_MAP_S;
	else
		get_g()->pl_s_dir = FLAG_MAP_ERROR;
}

int	process_line(char *op_str, char **line, int i, int map_flag)
{
	int	op_symbol;

	op_symbol = is_option_symbol(op_str);
	if (op_symbol >= 0 && get_g()->op_flags[op_symbol] == 0 && map_flag == 0)
	{
		input_option_from_line(op_symbol, *line, i);
		get_g()->op_flags[op_symbol] = 1;
	}
	else if (is_map_symbol(*line[0]) == 1)
	{
		input_map_from_line(*line);
		map_flag = 1;
	}
	else
		ft_exit(0, "invalid option flag\n");
	free(*line);
	*line = NULL;
	return (map_flag);
}

void	read_cub(int fd)
{
	char	op_str[3];
	char	*line;
	int		gnl_flag;
	int		map_flag;
	int		i;

	gnl_flag = 1;
	get_g()->player_flag = 0;
	map_flag = 0;
	while (gnl_flag == 1)
	{
		gnl_flag = get_next_line(fd, &line);
		if (gnl_flag == -1)
			ft_exit(0, "gnl_flag == -1\n");
		if (line[0] == '\0')
		{
			free(line);
			if (map_flag == 1)
				ft_exit(0, "map_flag == 1\n");
			continue ;
		}
		i = read_option(line, op_str);
		map_flag = process_line(op_str, &line, i, map_flag);
		free(line);
	}
}

void	check_cub(void)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (get_g()->op_flags[i] != 1)
			ft_exit(0, "overlap option\n");
		i++;
	}
	if (get_g()->map_x < 3 || get_g()->map_y < 3)
		ft_exit(0, "too short map\n");
}

int	read_option(char *line, char *op_str)
{
	int	i;
	int	op_idx;

	i = 0;
	op_idx = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isupper(line[i]) == 1)
	{
		if (op_idx >= 2)
		{
			ft_exit(0, "invaild option flag\n");
		}
		op_str[op_idx] = line[i];
		op_idx++;
		i++;
	}
	op_str[op_idx] = '\0';
	return (i);
}
