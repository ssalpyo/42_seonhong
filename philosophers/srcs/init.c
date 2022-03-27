/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:45:16 by seonhong          #+#    #+#             */
/*   Updated: 2022/01/14 21:22:23 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	numeric(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9' || ft_strlen(av[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_p *p)
{
	if ((ac == 5 || ac == 6) && numeric(av))
	{
		p->a.total = ft_atoi(av[1]);
		p->a.die = ft_atoi(av[2]);
		p->a.eat = ft_atoi(av[3]);
		p->a.sleep = ft_atoi(av[4]);
		p->a.must_eat = -1;
		if (ac == 6)
			p->a.must_eat = ft_atoi(av[5]);
		if (p->a.total <= 0 || p->a.die <= 0 || p->a.eat <= 0 \
			|| p->a.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_mutex(t_p *p)
{
	pthread_mutex_init(&p->a.write_mutex, NULL);
	pthread_mutex_init(&p->a.dead, NULL);
	pthread_mutex_init(&p->a.time_eat, NULL);
	pthread_mutex_init(&p->a.finish, NULL);
}

int	initialize(t_p *p)
{
	int	i;

	i = 0;
	p->a.time_start = get_time();
	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	init_mutex(p);
	while (i < p->a.total)
	{
		p->ph[i].id = i + 1;
		p->ph[i].must_eat = p->a.time_start;
		p->ph[i].nb_eat = 0;
		p->ph[i].finish = 0;
		p->ph[i].right_fork = NULL;
		pthread_mutex_init(&p->ph[i].left_fork, NULL);
		if (p->a.total == 1)
			return (1);
		if (i == p->a.total - 1)
			p->ph[i].right_fork = &p->ph[0].left_fork;
		else
			p->ph[i].right_fork = &p->ph[i + 1].left_fork;
		i++;
	}
	return (1);
}
