/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:11:51 by jayi              #+#    #+#             */
/*   Updated: 2022/02/08 16:39:23 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H

# include "color.h"

typedef struct s_img			t_img;
typedef struct s_ray			t_ray;
typedef struct s_node			t_node;
typedef struct s_vector			t_vector;
typedef struct s_player			t_player;
typedef struct s_texture		t_texture;
typedef struct s_vector_f		t_vector_f;
typedef struct s_game_model		t_game_model;
typedef struct s_wall_value		t_wall_value;

struct	s_wall_value
{
	int				draw_s_y;
	int				draw_e_y;
	int				line_h;
	int				wall_dir;
	int				tex_x;
	int				tex_y;
	int				x;
	int				y;
	double			wall_x;
	double			step;
	double			tex_pos;
	double			cam_x;
	unsigned int	color;
};

struct	s_vector
{
	int		x;
	int		y;
	int		z;
};

struct	s_vector_f
{
	double		x;
	double		y;
	double		z;
};

struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		endian;
	int		height;
	int		width;
	int		bpp;
};

struct	s_player
{
	t_vector_f	pos;
	t_vector_f	dir;
	t_vector_f	speed;
};

struct	s_node {
	void	*value;
	t_node	*next;
};

struct	s_game_model
{
	t_vector_f		cam;
	t_vector		sc_size;
	t_player		pl;
	t_color			f_color;
	t_color			c_color;
	t_node			*str_map;
	unsigned int	input_keys;
	double			z_buf[5000];
	double			fps;
	void			*sc_img;
	void			*mlx;
	void			*win;
	char			**w_map;
	char			**map_data;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*s_path;
	int				**sc_data_2d;
	int				*sc_data_1d;
	int				tmp_h;
	int				tmp_w;
	int				pl_s_x;
	int				pl_s_y;
	int				pl_s_dir;
	int				player_flag;
	int				textures[5][64 * 64];
	int				op_flags[6];
	int				map_y;
	int				map_x;
	int				sc_bpp;
	int				sc_endian;
	int				sc_s_line;
};

struct	s_ray
{
	t_vector_f		dir;
	t_vector_f		s_dist;
	t_vector_f		d_dist;
	t_vector		map;
	t_vector		step;
	double			p_dist;
	int				hit;
	int				side;
};

#endif
