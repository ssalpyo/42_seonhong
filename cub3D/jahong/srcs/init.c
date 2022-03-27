/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:01:56 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 17:19:08 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "init.h"
#include "utility.h"
#include "mlx.h"
#include "vector.h"
#include <stdlib.h>

static double	g_s_dirs[4][4] =
{
	{0, -1, -0.66, 0},
	{1, 0, 0, -0.66},
	{-1, 0, 0, 0.66},
	{0, 1, 0.66, 0},
};

static void	init_player(t_player *pl)
{
	pl->pos.x = get_g()->pl_s_x + 0.5;
	pl->pos.y = get_g()->pl_s_y + 0.5;
	pl->dir.x = g_s_dirs[get_g()->pl_s_dir][0];
	pl->dir.y = g_s_dirs[get_g()->pl_s_dir][1];
	get_g()->cam.x = g_s_dirs[get_g()->pl_s_dir][2];
	get_g()->cam.y = g_s_dirs[get_g()->pl_s_dir][3];
	pl->speed = v_zero();
}

static void	init_mlx(t_game_model *g)
{
	int	i;

	i = 0;
	g->mlx = mlx_init();
	g->sc_size.x = 1920;
	g->sc_size.y = 1080;
	g->win = mlx_new_window(g->mlx, g->sc_size.x, g->sc_size.y, TITLE_NAME);
	g->sc_img = mlx_new_image(g->mlx, g->sc_size.x, g->sc_size.y);
	g->sc_data_1d = (int *)mlx_get_data_addr(\
		g->sc_img, &g->sc_bpp, &g->sc_s_line, &g->sc_endian);
	g->sc_data_2d = malloc(sizeof(int *) * g->sc_size.y);
	g->sc_data_2d[0] = malloc(sizeof(int) * g->sc_size.y * g->sc_size.x);
	while (i < g->sc_size.y)
	{
		g->sc_data_2d[i] = g->sc_data_2d[0] + g->sc_size.x * i;
		++i;
	}
	g->map_data = get_g()->w_map;
	g->input_keys = 0;
	g->fps = 0;
}

void	load_image(t_game_model *g, int *texture, char *path)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(g->mlx, path, &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(\
		img.img, &img.bpp, &img.size_l, &img.endian);
	y = 0;
	while (y < img.height)
	{
		x = 0;
		while (x < img.width)
		{
			texture[img.width * y + x] = img.data[img.width * y + x];
			++x;
		}
		++y;
	}
	mlx_destroy_image(g->mlx, img.img);
}

void	init_texture(t_game_model *g)
{
	load_image(g, g->textures[TEX_WALL_N], g->no_path);
	load_image(g, g->textures[TEX_WALL_S], g->so_path);
	load_image(g, g->textures[TEX_WALL_W], g->we_path);
	load_image(g, g->textures[TEX_WALL_E], g->ea_path);
}

void	init_game(t_game_model *game_model, char *filename)
{
	parse_cub(filename);
	init_mlx(game_model);
	init_player(&(game_model->pl));
	init_texture(game_model);
}
