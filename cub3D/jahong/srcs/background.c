/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:40:53 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:54:01 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "background.h"

void	draw_sky(t_game_model *game_model)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game_model->sc_size.y / 2)
	{
		x = 0;
		if (y < game_model->sc_size.y)
		{
			while (x < game_model->sc_size.x)
			{
				game_model->sc_data_2d[y][x] = game_model->c_color.color;
				++x;
			}
		}
		++y;
	}
}

void	draw_ground(t_game_model *game_model)
{
	int	y;
	int	x;

	y = game_model->sc_size.y / 2;
	x = 0;
	while (y < game_model->sc_size.y)
	{
		x = 0;
		while (x < game_model->sc_size.x)
		{
			game_model->sc_data_2d[y][x] = game_model->f_color.color;
			++x;
		}
		++y;
	}
}
