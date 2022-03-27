/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:46:55 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:56:17 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "input.h"
#include "logic.h"
#include "mlx.h"
#include "ray.h"
#include <math.h>

static	void	calc_wall_height(
	t_ray *ray, t_wall_value *v, t_game_model *g)
{
	v->line_h = (int)(g->sc_size.y / ray->p_dist);
	v->draw_s_y = -v->line_h / 2 + g->sc_size.y / 2;
	if (v->draw_s_y < 0)
		v->draw_s_y = 0;
	v->draw_e_y = v->line_h / 2 + g->sc_size.y / 2;
	if (v->draw_e_y >= g->sc_size.y)
		v->draw_e_y = g->sc_size.y;
}

static	void	calc_texture(
	t_ray *ray, t_wall_value *v, t_player *pl, t_game_model *g)
{
	if (ray->side == RAY_SIDE_X)
		v->wall_x = pl->pos.y + ray->p_dist * ray->dir.y;
	else
		v->wall_x = pl->pos.x + ray->p_dist * ray->dir.x;
	v->wall_x -= floor(v->wall_x);
	v->tex_x = (int)(v->wall_x * TEX_WIDTH);
	if (ray->side == RAY_SIDE_X && ray->dir.x > 0)
		v->tex_x = TEX_WIDTH - v->tex_x - 1;
	if (ray->side == RAY_SIDE_Y && ray->dir.y < 0)
		v->tex_x = TEX_WIDTH - v->tex_x - 1;
	v->step = (double)TEX_HEIGHT / v->line_h;
	v->tex_pos = (v->draw_s_y - g->sc_size.y / 2 + v->line_h / 2) * v->step;
	if (ray->side == RAY_SIDE_Y && ray->step.y == 1)
		v->wall_dir = TEX_WALL_N;
	else if (ray->side == RAY_SIDE_Y && ray->step.y == -1)
		v->wall_dir = TEX_WALL_S;
	if (ray->side == RAY_SIDE_X && ray->step.x == 1)
		v->wall_dir = TEX_WALL_W;
	else if (ray->side == RAY_SIDE_X && ray->step.x == -1)
		v->wall_dir = TEX_WALL_E;
}

static	void	calc_color(t_ray *ray, t_wall_value *v, t_game_model *g)
{
	v->y = v->draw_s_y;
	while (v->y < v->draw_e_y)
	{
		v->tex_y = (int)v->tex_pos & (TEX_HEIGHT - 1);
		v->tex_pos += v->step;
		v->color = g->textures[v->wall_dir][TEX_HEIGHT * v->tex_y + v->tex_x];
		if (ray->side == RAY_SIDE_Y)
			v->color = (v->color >> 1) & 8355711;
		g->sc_data_2d[v->y][v->x] = v->color;
		++v->y;
	}
}

int	draw_wall(t_game_model *g)
{
	t_ray			ray;
	t_player		*pl;
	t_vector_f		dir;
	t_wall_value	v;

	v.x = 0;
	pl = &(g->pl);
	while (v.x < g->sc_size.x)
	{
		v.cam_x = 2 * v.x / (double)g->sc_size.x - 1;
		dir.x = pl->dir.x + g->cam.x * v.cam_x;
		dir.y = pl->dir.y + g->cam.y * v.cam_x;
		if (raycast(g, __LDBL_MAX__, dir, &ray))
		{
			calc_wall_height(&ray, &v, g);
			calc_texture(&ray, &v, pl, g);
			calc_color(&ray, &v, g);
			g->z_buf[v.x] = ray.p_dist;
		}
		++v.x;
	}
	return (0);
}
