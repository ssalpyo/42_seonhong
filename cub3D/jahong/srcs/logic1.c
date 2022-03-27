/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:31:39 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:51:33 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "logic.h"
#include "define.h"
#include "input.h"
#include "wall.h"
#include "vector.h"
#include "init.h"
#include "ray.h"
#include "utility.h"
#include "background.h"
#include "object.h"
#include "player.h"
#include "color.h"
#include <stdlib.h>
#include <math.h>

void	draw(t_game_model *g)
{
	draw_sky(g);
	draw_ground(g);
	draw_wall(g);
}

void	render(t_game_model *g)
{
	int	j;
	int	i;

	j = 0;
	while (j < g->sc_size.y)
	{
		i = 0;
		while (i < g->sc_size.x)
		{
			g->sc_data_1d[j * g->sc_size.x + i] = g->sc_data_2d[j][i];
			++i;
		}
		++j;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->sc_img, 0, 0);
}

int	game_loop(t_game_model *g)
{
	pre_update(g);
	update(g);
	draw(g);
	render(g);
	return (0);
}

void	attach_hook(t_game_model *g)
{
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, handle_key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_RELEASE, 0, handle_key_release, g);
	mlx_hook(g->win, X_EVENT_DESTROY_NOTIFY, 0, exit_game, g);
	mlx_loop_hook(g->mlx, game_loop, g);
}

int	start_game(char *filename)
{
	init_game(get_g(), filename);
	attach_hook(get_g());
	mlx_loop(get_g()->mlx);
	return (0);
}
