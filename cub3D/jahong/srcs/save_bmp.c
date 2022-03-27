/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:25:28 by jayi              #+#    #+#             */
/*   Updated: 2022/02/07 20:13:16 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utility_mem.h"
#include "utility.h"
#include "logic.h"
#include "init.h"
#include <unistd.h>
#include <fcntl.h>

static void	bmp_header(t_game_model *g, int fd)
{
	int		tmp;
	char	header[BITMAPFILEHEADER];
	char	info[BITMAPINFOHEADER];

	ft_memset(&header, 0, BITMAPFILEHEADER);
	ft_memset(&info, 0, BITMAPINFOHEADER);
	ft_memmove(&header[0], "BM", 2);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER + \
		(g->sc_bpp / 8) * g->sc_size.x * g->sc_size.y;
	ft_memmove(&header[2], &tmp, 4);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER;
	ft_memmove(&header[10], &tmp, 4);
	write(fd, header, BITMAPFILEHEADER);
	tmp = BITMAPINFOHEADER;
	ft_memmove(&info[0], &tmp, 4);
	ft_memmove(&info[4], &g->sc_size.x, 4);
	ft_memmove(&info[8], &g->sc_size.y, 4);
	tmp = 1;
	ft_memmove(&info[12], &tmp, 2);
	ft_memmove(&info[14], &g->sc_bpp, 2);
	write(fd, info, BITMAPINFOHEADER);
}

static void	bmp_data(t_game_model *g, int fd)
{
	int		x;
	int		y;

	y = g->sc_size.y;
	while (y-- > 0)
	{
		x = -1;
		while (++x < g->sc_size.x)
			write(fd, &g->sc_data_1d[y * g->sc_size.x + x], (g->sc_bpp / 8));
	}
}

int	save_bmp(t_game_model *g, char *filename)
{
	int		fd;

	fd = open("./image.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IWUSR | S_IRUSR);
	if (fd == -1)
		ft_exit(0, "save_bmp file error\n");
	init_game(g, filename);
	game_loop(g);
	bmp_header(g, fd);
	bmp_data(g, fd);
	close(fd);
	return (0);
}
