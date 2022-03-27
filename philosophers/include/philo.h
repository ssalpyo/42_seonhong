/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:49:04 by seonhong          #+#    #+#             */
/*   Updated: 2022/01/14 19:38:17 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg
{
	int						total;
	int						die;
	int						eat;
	int						sleep;
	int						must_eat;
	long int				time_start;
	int						nb_p_finish;
	int						stop;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
}							t_arg;

typedef struct s_philo
{
	int						id;
	long int				must_eat;
	unsigned int			nb_eat;
	int						finish;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	t_arg					*pa;
}							t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}							t_p;

int			parse_args(int argc, char **argv, t_p *p);
int			initialize(t_p *p);
void		write_status(char *str, t_philo *ph);
int			threading(t_p *p);
void		activity(t_philo *ph);
int			check_death(t_philo *ph, int i);
long int	get_time(void);
void		ft_usleep(long int time_in_ms);
int			ft_exit(char *str);
size_t		ft_strlen(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);

#endif