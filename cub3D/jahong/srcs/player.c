/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:56:28 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:53:37 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	control_player(t_game_model *game_model)
{
	add_speed(&game_model->pl, game_model->input_keys);
}

void	rotate_player(t_game_model *game_model)
{
	if (game_model->input_keys & KEY_BIT_LEFT)
	{
		v_rotate_ref(&(game_model->pl.dir), PLAYER_ROTATE);
		v_rotate_ref(&(game_model->cam), PLAYER_ROTATE);
	}
	if (game_model->input_keys & KEY_BIT_RIGHT)
	{
		v_rotate_ref(&(game_model->pl.dir), -PLAYER_ROTATE);
		v_rotate_ref(&(game_model->cam), -PLAYER_ROTATE);
	}
}
