/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:45:42 by jayi              #+#    #+#             */
/*   Updated: 2022/02/05 14:50:33 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "vector.h"
#include <math.h>

t_vector_f	v_multi(t_vector_f vec, double value)
{
	t_vector_f	new_vec;

	new_vec.x = vec.x * value;
	new_vec.y = vec.y * value;
	new_vec.z = vec.z * value;
	return (new_vec);
}

int	v_is_zero(t_vector_f vec)
{
	return (fabs(vec.x) <= __DBL_EPSILON__ && fabs(vec.y) <= __DBL_EPSILON__ && \
	fabs(vec.z) <= __DBL_EPSILON__);
}

t_vector_f	v_normalize(t_vector_f vec)
{
	t_vector_f	new_vec;
	double		length;

	if (v_is_zero(vec))
		return (vec);
	length = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	new_vec.x = vec.x / length;
	new_vec.y = vec.y / length;
	new_vec.z = vec.z / length;
	return (new_vec);
}

void	v_rotate_ref(t_vector_f *dir, double angle)
{
	double	final_x;
	double	final_y;
	double	rad;

	rad = 2 * M_PI * angle / 360;
	final_x = cos(rad) * dir->x - sin(rad) * dir->y;
	final_y = sin(rad) * dir->x + cos(rad) * dir->y;
	dir->x = final_x;
	dir->y = final_y;
}

t_vector_f	v_rotate(t_vector_f dir, double angle)
{
	t_vector_f	new_dir;
	double		rad;

	new_dir.x = dir.x;
	new_dir.y = dir.y;
	new_dir.z = dir.z;
	rad = 2 * M_PI * angle / 360;
	new_dir.x = cos(rad) * dir.x - sin(rad) * dir.y;
	new_dir.y = sin(rad) * dir.x + cos(rad) * dir.y;
	return (new_dir);
}
