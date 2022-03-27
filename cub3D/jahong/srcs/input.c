/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:30:54 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:53:04 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "input.h"
#include "utility.h"

static unsigned int	get_key_bit(int keycode)
{
	if (keycode == KEYCODE_DOWN)
		return (KEY_BIT_DOWN);
	else if (keycode == KEYCODE_UP)
		return (KEY_BIT_UP);
	else if (keycode == KEYCODE_LEFT)
		return (KEY_BIT_LEFT);
	else if (keycode == KEYCODE_RIGHT)
		return (KEY_BIT_RIGHT);
	else if (keycode == KEYCODE_Q)
		return (KEY_BIT_Q);
	else if (keycode == KEYCODE_E)
		return (KEY_BIT_E);
	else if (keycode == KEYCODE_W)
		return (KEY_BIT_W);
	else if (keycode == KEYCODE_S)
		return (KEY_BIT_S);
	else if (keycode == KEYCODE_A)
		return (KEY_BIT_A);
	else if (keycode == KEYCODE_D)
		return (KEY_BIT_D);
	else if (keycode == KEYCODE_ESC)
		return (KEY_BIT_ESC);
	return (0);
}

unsigned int	press_key(int keycode, unsigned int input_keys)
{
	input_keys |= get_key_bit(keycode);
	return (input_keys);
}

unsigned int	release_key(int keycode, unsigned int input_keys)
{
	input_keys &= ~get_key_bit(keycode);
	return (input_keys);
}

int	handle_key_press(int keycode, t_game_model *game_model)
{
	game_model->input_keys = press_key(keycode, game_model->input_keys);
	return (0);
}

int	handle_key_release(int keycode, t_game_model *game_model)
{
	game_model->input_keys = release_key(keycode, game_model->input_keys);
	return (0);
}
