/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:29:59 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/30 13:42:20 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *map_name)
{
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		exit_err("File open fail.\n");
	return (fd);
}

void	get_map_size(t_game *game, int fd)
{
	char	c;
	int		temp_col;

	temp_col = 0;
	game->maps.row = 0;
	game->maps.col = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (game->maps.col < temp_col)
			game->maps.col = temp_col;
		if (c == '\n')
		{
			game->maps.row++;
			temp_col = 0;
		}
		else
			temp_col++;
	}
}

void	alloc_map(t_game *game, int fd)
{
	int	i;

	i = 0;
	get_map_size(game, fd);
	game->maps.map = (char **)ft_calloc(game->maps.row + 1, sizeof(char *));
	if (game->maps.map == NULL)
		exit_err("Malloc fail\n");
	while (i < game->maps.row)
	{
		game->maps.map[i] = (char *)ft_calloc(game->maps.col + 1, sizeof(char));
		if (game->maps.map[i] == NULL)
			exit_err("Malloc fail\n");
		i++;
	}
}

void	parse_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open_file(map_name);
	while (get_next_line(fd, &line) > 0)
	{
		check_map_square(game, ft_strlen(line));
		j = -1;
		while (++j < game->maps.col)
		{
			if (check_map_elements(line[j]) == 1)
				game->maps.map[i][j] = line[j];
			else
				exit_err("Invalid map elements.\n");
		}
		game->maps.map[i][j] = '\0';
		++i;
		free(line);
	}
	game->maps.map[i] = 0;
	free(line);
	close(fd);
}

void	read_map(t_game *game, char *map_name)
{
	int	fd;

	fd = open_file(map_name);
	alloc_map(game, fd);
	close(fd);
	parse_map(game, map_name);
	check_map_walls(game->maps);
	check_player_num(game->maps);
}
