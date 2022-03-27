/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:10:23 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/30 02:59:26 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->maps.map[i] != 0)
	{
		j = ft_strchr_idx(game->maps.map[i], 'P');
		if (j != 0)
			break ;
		i++;
	}
	if (game->maps.map[i - 1][j] != '1' && game->maps.map[i - 1][j] != 'E')
	{
		game->maps.map[i][j] = '0';
		game->maps.map[i - 1][j] = 'P';
		game->move_num++;
		ft_putnbr_fd(game->move_num, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_destroy_image(game->mlx, game->player);
	load_img(game, &game->player, "./assets/player.xpm");
}

void	move_down(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->maps.map[i] != 0)
	{
		j = ft_strchr_idx(game->maps.map[i], 'P');
		if (j != 0)
			break ;
		i++;
	}
	if (game->maps.map[i + 1][j] != '1' && game->maps.map[i + 1][j] != 'E')
	{
		game->maps.map[i][j] = '0';
		game->maps.map[i + 1][j] = 'P';
		game->move_num++;
		ft_putnbr_fd(game->move_num, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_destroy_image(game->mlx, game->player);
	load_img(game, &game->player, "./assets/player.xpm");
}

void	move_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->maps.map[i] != 0)
	{
		j = ft_strchr_idx(game->maps.map[i], 'P');
		if (j != 0)
			break ;
		i++;
	}
	if (game->maps.map[i][j - 1] != '1' && game->maps.map[i][j - 1] != 'E')
	{
		game->maps.map[i][j] = '0';
		game->maps.map[i][j - 1] = 'P';
		game->move_num++;
		ft_putnbr_fd(game->move_num, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_destroy_image(game->mlx, game->player);
	load_img(game, &game->player, "./assets/player.xpm");
}

void	move_right(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->maps.map[i] != 0)
	{
		j = ft_strchr_idx(game->maps.map[i], 'P');
		if (j != 0)
			break ;
		i++;
	}
	if (game->maps.map[i][j + 1] != '1' && game->maps.map[i][j + 1] != 'E')
	{
		game->maps.map[i][j] = '0';
		game->maps.map[i][j + 1] = 'P';
		game->move_num++;
		ft_putnbr_fd(game->move_num, 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_destroy_image(game->mlx, game->player);
	load_img(game, &game->player, "./assets/player.xpm");
}
