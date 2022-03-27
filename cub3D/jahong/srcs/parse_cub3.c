/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:41:40 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:37:33 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "define.h"
#include "utility.h"
#include "lst.h"
#include "color.h"
#include <stdlib.h>

void	input_map_from_row(char *map_row)
{
	t_node	*new_node;
	t_node	*cur;

	get_g()->map_y++;
	new_node = malloc(sizeof(t_node));
	new_node->value = map_row;
	new_node->next = NULL;
	if (get_g()->str_map == NULL)
	{
		get_g()->str_map = new_node;
		return ;
	}
	cur = get_g()->str_map;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
}

void	input_map_from_line(char *line)
{
	int		i;
	int		max_col;
	char	*map_row;

	i = 0;
	max_col = 0;
	while (line[i] != '\0')
	{
		if (is_map_symbol(line[i++]) == 1)
			max_col++;
		else
			ft_exit(0, "invalid map symbol\n");
	}
	if (get_g()->map_x < max_col)
		get_g()->map_x = max_col;
	map_row = malloc(sizeof(char) * (max_col + 1));
	i = 0;
	while (line[i] != '\0')
	{
		map_row[i] = line[i];
		i++;
	}
	map_row[i] = '\0';
	input_map_from_row(map_row);
}

int	allocate_map(void)
{
	int	i;

	get_g()->w_map = malloc(sizeof(char *) * get_g()->map_x);
	get_g()->w_map[0] = malloc(sizeof(char) * get_g()->map_y * get_g()->map_x);
	if (get_g()->w_map == NULL || get_g()->w_map[0] == NULL)
	{
		free(get_g()->w_map);
		free(get_g()->w_map[0]);
		ft_exit(0, "worldmap malloc error\n");
	}
	i = 1;
	while (i < get_g()->map_x)
	{
		get_g()->w_map[i] = get_g()->w_map[0] + get_g()->map_y * i;
		i++;
	}
	return (1);
}

void	parse_map(void)
{
	t_node	*cur;
	char	*v;
	int		x;
	int		y;

	y = -1;
	cur = get_g()->str_map;
	while (++y < get_g()->map_y)
	{
		x = 0;
		v = cur->value;
		while (v[x] != '\0')
		{
			if (v[x] == 'N' || v[x] == 'E' || v[x] == 'W' || v[x] == 'S')
				input_player_location(x, y, v[x]);
			else if (v[x] == '0')
				get_g()->w_map[x][y] = 0;
			else
				get_g()->w_map[x][y] = 1;
			x++;
		}
		cur = cur->next;
	}
}
