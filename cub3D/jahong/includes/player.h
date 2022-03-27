/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:14:27 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 23:14:40 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "define.h"
# include "vector.h"
# include "input.h"
# include "object.h"

void	rotate_player(t_game_model *game_model);
void	control_player(t_game_model *game_model);

#endif
