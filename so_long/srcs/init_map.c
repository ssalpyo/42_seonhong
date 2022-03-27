/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:09:05 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/30 01:46:02 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_map(t_game *game, int i, int j)
{
	put_img_to_win(game, game->tile, j, i);
	if (game->maps.map[i][j] == '1')
		put_img_to_win(game, game->tree, j, i);
	else if (game->maps.map[i][j] == 'C')
		put_img_to_win(game, game->collect, j, i);
	else if (game->maps.map[i][j] == 'P')
		put_img_to_win(game, game->player, j, i);
	else if (game->maps.map[i][j] == 'E' || game->maps.map[i][j] == 'X')
		put_img_to_win(game, game->exit, j, i);
}

void	init_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maps.row)
	{
		j = 0;
		while (j < game->maps.col)
		{
			draw_map(game, i, j);
			++j;
		}
		++i;
	}
}
