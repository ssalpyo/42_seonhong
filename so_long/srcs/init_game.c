/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:28:16 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/30 01:45:40 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_game *game, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (*img == 0)
		exit_err("image load fail\n");
	(*img)->width = width;
	(*img)->height = height;
}

void	init_img(t_game *game)
{
	load_img(game, &game->tile, "./assets/tile.xpm");
	load_img(game, &game->tree, "./assets/tree.xpm");
	load_img(game, &game->player, "./assets/player.xpm");
	load_img(game, &game->collect, "./assets/collect.xpm");
	load_img(game, &game->exit, "./assets/exit.xpm");
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	game->exit_cnt = 0;
	game->move_num = 0;
	width = game->maps.col * 64;
	height = game->maps.row * 64;
	game->mlx = mlx_init();
	if (game->mlx == 0)
		exit_err("mlx_init fail\n");
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (game->win == 0)
		exit_err("mlx_new_window fail\n");
	init_img(game);
}
