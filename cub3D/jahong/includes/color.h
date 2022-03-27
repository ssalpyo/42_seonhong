/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:09:35 by jayi              #+#    #+#             */
/*   Updated: 2022/02/07 19:52:09 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union u_color
{
	struct s_bit
	{
		unsigned int	b	:8;
		unsigned int	g	:8;
		unsigned int	r	:8;
		unsigned int	a	:8;
	}					bit;
	unsigned int		color;
}	t_color;

#endif
