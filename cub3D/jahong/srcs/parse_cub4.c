/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:54:13 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 17:13:19 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "define.h"
#include "utility.h"
#include <fcntl.h>
#include <stdlib.h>

void	option_color(char *line, int i, t_color *color)
{
	color->color = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]) == 1)
		color->bit.r = color->bit.r * 10 + line[i++] - '0';
	if (line[i] == ',')
		i++;
	while (ft_isdigit(line[i]) == 1)
		color->bit.g = color->bit.g * 10 + line[i++] - '0';
	if (line[i] == ',')
		i++;
	while (ft_isdigit(line[i]) == 1)
		color->bit.b = color->bit.b * 10 + line[i++] - '0';
	while (line[i] != '\0')
		if (ft_isspace(line[i++]) == 0)
			ft_exit(0, "invalid color option input\n");
}

void	option_path(char *line, int start, char **path)
{
	int		i;
	int		path_idx;
	char	*new_path;

	while (line[start] == ' ')
		start++;
	i = start;
	path_idx = 0;
	while (line[i] != '\0')
	{
		path_idx++;
		i++;
	}
	check_file(&line[start], O_RDONLY);
	new_path = malloc(sizeof(char) * (path_idx + 1));
	i = start;
	path_idx = 0;
	while (line[i] != '\0')
	{
		new_path[path_idx] = line[i];
		path_idx++;
		i++;
	}
	new_path[path_idx] = '\0';
	*path = new_path;
}

void	input_option_from_line(int op_symbol, char *line, int i)
{
	if (op_symbol == OP_NO)
		option_path(line, i, &get_g()->no_path);
	else if (op_symbol == OP_SO)
		option_path(line, i, &get_g()->so_path);
	else if (op_symbol == OP_WE)
		option_path(line, i, &get_g()->we_path);
	else if (op_symbol == OP_EA)
		option_path(line, i, &get_g()->ea_path);
	else if (op_symbol == OP_F)
		option_color(line, i, &get_g()->f_color);
	else if (op_symbol == OP_C)
		option_color(line, i, &get_g()->c_color);
	else
		ft_exit(0, "not exists option\n");
}

int	is_option_symbol(char *str)
{
	if (ft_strcmp(str, FLAG_NORTH) == 0)
		return (OP_NO);
	else if (ft_strcmp(str, FLAG_SOUTH) == 0)
		return (OP_SO);
	else if (ft_strcmp(str, FLAG_WEST) == 0)
		return (OP_WE);
	else if (ft_strcmp(str, FLAG_EAST) == 0)
		return (OP_EA);
	else if (ft_strcmp(str, FLAG_FLOOR) == 0)
		return (OP_F);
	else if (ft_strcmp(str, FLAG_CELLING) == 0)
		return (OP_C);
	else
		return (-1);
}
