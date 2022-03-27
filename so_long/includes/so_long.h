/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:27:05 by seonhong          #+#    #+#             */
/*   Updated: 2021/10/30 13:41:12 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../library/includes/libft.h"
# include "../library/includes/get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
}			t_map;

typedef struct s_img
{
	int		width;
	int		height;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	maps;
	t_img	*player;
	t_img	*tile;
	t_img	*tree;
	t_img	*collect;
	t_img	*exit;
	int		exit_cnt;
	int		move_num;
}				t_game;

void	read_map(t_game *game, char *map_name);
void	init_game(t_game *game);
void	check_arg(int argc, char **argv);
void	check_map_square(t_game *game, int len);
int		check_map_elements(char c);
void	check_map_walls(t_map maps);
void	check_player_num(t_map maps);
void	init_map(t_game *game);
void	load_img(t_game *game, t_img **img, char *path);
int		key_hook(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		close_game(t_game *game);
int		ft_strchr_idx(char *s, int c);
void	exit_err(char *str);
void	put_img_to_win(t_game *game, void *img, int x, int y);

#endif