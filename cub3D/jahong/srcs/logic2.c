/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:31:39 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:54:06 by jayi             ###   ########.fr       */
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

void	handle_input_keys(t_game_model *g)
{
	if (g->input_keys & KEY_BIT_ESC)
		exit_game();
	control_player(g);
	rotate_player(g);
}

void	pre_update(t_game_model *g)
{
	clear_data(g->sc_data_1d, g->sc_size.x, g->sc_size.y);
	handle_input_keys(g);
}

void	update_player_pos(t_game_model *g)
{
	t_player	*pl;

	pl = &g->pl;
	if (!v_is_zero(pl->speed))
	{
		if (raycast(g, (0.1 + 0.01), v_x_axis(pl->speed), NULL) == 0)
			pl->pos.x += pl->speed.x * 0.1;
		if (raycast(g, (0.1 + 0.01), v_y_axis(pl->speed), NULL) == 0)
			pl->pos.y += pl->speed.y * 0.1;
		pl->speed = v_zero();
	}
}

void	update(t_game_model *g)
{
	update_player_pos(g);
}
