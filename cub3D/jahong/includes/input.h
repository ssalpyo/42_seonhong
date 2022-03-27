/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:35:03 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:53:15 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define KEY_BIT_DOWN 1
# define KEY_BIT_UP 2
# define KEY_BIT_LEFT 4
# define KEY_BIT_RIGHT 8
# define KEY_BIT_Q 32
# define KEY_BIT_E 64
# define KEY_BIT_W 128
# define KEY_BIT_S 256
# define KEY_BIT_A 512
# define KEY_BIT_D 1024
# define KEY_BIT_ESC 2048
# define KEYCODE_LEFT 123
# define KEYCODE_RIGHT 124
# define KEYCODE_DOWN 125
# define KEYCODE_UP 126
# define KEYCODE_Q 12
# define KEYCODE_W 13
# define KEYCODE_E 14
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2
# define KEYCODE_ESC 53

unsigned int	press_key(int keycode, unsigned int input_keys);
unsigned int	release_key(int keycode, unsigned int input_keys);
int				handle_key_press(int keycode, t_game_model *game_model);
int				handle_key_release(int keycode, t_game_model *game_model);

#endif
