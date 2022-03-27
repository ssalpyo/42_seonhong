/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:11:39 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/30 02:04:38 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx, game->win);
	while (i <= game->maps.row)
		free(game->maps.map[i++]);
	free(game->maps.map);
	exit(0);
}

void	check_game_finished(t_game *game)
{
	int	x_cnt;

	if (ft_strschr(game->maps.map, 'E') == 0)
	{
		x_cnt = ft_strschr(game->maps.map, 'X');
		if (x_cnt == game->exit_cnt - 1)
			close_game(game);
	}
}

void	check_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strschr(game->maps.map, 'C') == 0)
	{
		while (game->maps.map[i] != 0)
		{
			j = 0;
			while (game->maps.map[i][j] != '\0')
			{
				if (game->maps.map[i][j] == 'E')
				{
					game->maps.map[i][j] = 'X';
					game->exit_cnt++;
				}
				j++;
			}
			i++;
		}
	}	
}

int	key_hook(int keycode, t_game *game)
{
	check_collect(game);
	if (keycode == 53)
		close_game(game);
	if (keycode == 13)
		move_up(game);
	if (keycode == 1)
		move_down(game);
	if (keycode == 0)
		move_left(game);
	if (keycode == 2)
		move_right(game);
	check_game_finished(game);
	init_map(game);
	return (1);
}
