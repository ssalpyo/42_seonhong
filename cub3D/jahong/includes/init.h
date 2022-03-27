/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:24:38 by jayi              #+#    #+#             */
/*   Updated: 2022/02/07 20:20:16 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "define.h"

void	init_game(t_game_model *game_model, char *filename);
void	input_player_location(int i, int j, int direction);
int		process_line(char *op_str, char **line, int i, int map_flag);
void	read_cub(int fd);
void	check_cub(void);
void	parse(char *filename);
void	parse_cub(char *filename);
int		is_map_symbol(char c);
void	input_map_from_row(char *map_row);
void	input_map_from_line(char *line);
int		allocate_map(void);
void	parse_map(void);
void	check_map(int map_row, int map_col);
void	rewind_map(void);
void	option_color(char *line, int i, t_color *color);
void	option_path(char *line, int start, char **path);
int		read_option(char *line, char *op_str);
void	input_option_from_line(int op_symbol, char *line, int i);
int		is_option_symbol(char *str);

#endif
