/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:40:16 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:53:28 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	add_speed(t_player *object, int direction)
{
	t_vector_f	new_dir;

	new_dir = v_zero();
	if (direction & KEY_BIT_W)
		new_dir = v_plus(new_dir, object->dir);
	if (direction & KEY_BIT_S)
		new_dir = v_plus(new_dir, v_reverse(object->dir));
	if (direction & KEY_BIT_A)
		new_dir = v_plus(new_dir, v_rotate(object->dir, 90));
	if (direction & KEY_BIT_D)
		new_dir = v_plus(new_dir, v_rotate(object->dir, -90));
	if (!v_is_zero(new_dir))
		object->speed = v_normalize(new_dir);
}
