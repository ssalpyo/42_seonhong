/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:06:06 by seonhong          #+#    #+#             */
/*   Updated: 2021/09/26 21:55:37 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_msg
{
	char	c;
	size_t	size;
}	t_msg;

long long	ft_atoi(const char *str);
size_t		ft_strlen(const char *str);

int			ft_isdigit_str(const char *s);

void		ft_error(void);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);

#endif
