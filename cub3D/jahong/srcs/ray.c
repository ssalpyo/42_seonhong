/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:57:21 by jayi              #+#    #+#             */
/*   Updated: 2022/02/07 19:18:46 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	init_ray_dir(t_ray *ray, t_player *pl)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->s_dist.x = (pl->pos.x - ray->map.x) * ray->d_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->s_dist.x = (ray->map.x + 1.0 - pl->pos.x) * ray->d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->s_dist.y = (pl->pos.y - ray->map.y) * ray->d_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->s_dist.y = (ray->map.y + 1.0 - pl->pos.y) * ray->d_dist.y;
	}
}

static void	init_ray(t_ray *ray, t_player *pl, t_vector_f dir)
{
	ray->dir.x = dir.x;
	ray->dir.y = dir.y;
	ray->map.x = (int)pl->pos.x;
	ray->map.y = (int)pl->pos.y;
	ray->d_dist.x = fabs(1 / ray->dir.x);
	ray->d_dist.y = fabs(1 / ray->dir.y);
	ray->hit = 0;
	ray->p_dist = 0;
	init_ray_dir(ray, pl);
}

static void	is_hit(t_game_model *g, t_ray *o_ray)
{
	while (o_ray->hit == 0)
	{
		if (o_ray->s_dist.x < o_ray->s_dist.y)
		{
			o_ray->s_dist.x += o_ray->d_dist.x;
			o_ray->map.x += o_ray->step.x;
			o_ray->side = RAY_SIDE_X;
		}
		else
		{
			o_ray->s_dist.y += o_ray->d_dist.y;
			o_ray->map.y += o_ray->step.y;
			o_ray->side = RAY_SIDE_Y;
		}
		if (g->map_data[o_ray->map.x][o_ray->map.y] > 0)
			o_ray->hit = 1;
	}
}

int	raycast(t_game_model *g,
					double length, t_vector_f dir, t_ray *o_ray)
{
	t_player	*pl;
	t_ray		ray;

	if (o_ray == NULL)
		o_ray = &ray;
	pl = &(g->pl);
	init_ray(o_ray, pl, dir);
	is_hit(g, o_ray);
	if (o_ray->hit == 1)
	{
		if (o_ray->side == 0)
			o_ray->p_dist = (o_ray->map.x - pl->pos.x + \
			(1 - o_ray->step.x) / 2) / o_ray->dir.x;
		else
			o_ray->p_dist = (o_ray->map.y - pl->pos.y + \
			(1 - o_ray->step.y) / 2) / o_ray->dir.y;
	}
	return (o_ray->hit && length >= o_ray->p_dist);
}
