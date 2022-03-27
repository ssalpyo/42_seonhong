/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:21:43 by jayi              #+#    #+#             */
/*   Updated: 2022/02/07 19:52:18 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "define.h"
# include <math.h>
# include <stdlib.h>

int	raycast(t_game_model *g, double length, t_vector_f dir, t_ray *out_ray);

#endif
