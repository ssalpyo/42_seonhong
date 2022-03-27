/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:35:09 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 23:24:21 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "define.h"

t_vector_f		v_reverse(t_vector_f vec);
t_vector_f		v_x_axis(t_vector_f vec);
t_vector_f		v_y_axis(t_vector_f vec);
t_vector_f		v_zero(void);
t_vector_f		v_plus(t_vector_f vec1, t_vector_f vec2);
t_vector_f		v_multi(t_vector_f vec, double value);
t_vector_f		v_normalize(t_vector_f vec);
t_vector_f		v_rotate(t_vector_f dir, double angle);
int				v_is_zero(t_vector_f vec);
void			v_rotate_ref(t_vector_f *dir, double angle);

#endif
