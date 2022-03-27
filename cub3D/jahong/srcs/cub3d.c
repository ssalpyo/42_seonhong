/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:42:57 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 15:43:13 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logic.h"
#include "utility.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		start_game(argv[1]);
	}
	else if (argc == 3)
	{
		if (ft_strcmp(argv[1], "--save") == 0)
			save_bmp(get_g(), argv[2]);
		else
			ft_exit(0, "invalid option");
	}
	else
		ft_exit(0, "invalid argument");
}
