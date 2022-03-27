/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:44:27 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/30 13:40:36 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		exit_err("Invalid number of argument.\n");
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
		exit_err("Invalid argument.\n");
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
		exit_err("Usage: ./so_long [MAP_FILE.ber]\n");
}

void	check_map_square(t_game *game, int len)
{
	if (len != game->maps.col)
		exit_err("Invalid map.\n");
}

int	check_map_elements(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

void	check_map_walls(t_map maps)
{
	int	i;

	i = 0;
	while (i < maps.row)
	{
		if (maps.map[i][0] != '1' || maps.map[i][maps.col - 1] != '1')
			exit_err("The map must be surrounded by walls.\n");
		++i;
	}
	i = 0;
	while (i < maps.col)
	{
		if (maps.map[0][i] != '1' || maps.map[maps.row - 1][i] != '1')
			exit_err("The map must be surrounded by walls.\n");
		++i;
	}
}

void	check_player_num(t_map maps)
{
	int	p_cnt;

	p_cnt = ft_strschr(maps.map, 'P');
	if (p_cnt != 1)
		exit_err("Only one player should be on the map\n");
}
