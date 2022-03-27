/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:45:42 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 22:52:06 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "vector.h"
#include <math.h>

t_vector_f	v_reverse(t_vector_f vec)
{
	t_vector_f	new_vec;

	new_vec.x = -vec.x;
	new_vec.y = -vec.y;
	new_vec.z = -vec.z;
	return (new_vec);
}

t_vector_f	v_x_axis(t_vector_f vec)
{
	t_vector_f	new_vec;

	new_vec.x = vec.x;
	new_vec.y = 0;
	new_vec.z = 0;
	return (new_vec);
}

t_vector_f	v_y_axis(t_vector_f vec)
{
	t_vector_f	new_vec;

	new_vec.x = 0;
	new_vec.y = vec.y;
	new_vec.z = 0;
	return (new_vec);
}

t_vector_f	v_zero(void)
{
	t_vector_f	new_vec;

	new_vec.x = 0;
	new_vec.y = 0;
	new_vec.z = 0;
	return (new_vec);
}

t_vector_f	v_plus(t_vector_f vec1, t_vector_f vec2)
{
	t_vector_f	new_vec;

	new_vec.x = vec1.x + vec2.x;
	new_vec.y = vec1.y + vec2.y;
	new_vec.z = vec1.z + vec2.z;
	return (new_vec);
}
