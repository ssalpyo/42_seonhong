/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:35:28 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/07 22:27:57 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_info
{
	int		*a;
	int		*b;
	int		a_top;
	int		b_top;
	int		size;
}				t_info;

void			checker(int argc, char *argv[]);

void			setting_num(t_info *info, int argc, char *argv[]);

void			sa(t_info *info);
void			sb(t_info *info);
void			ss(t_info *info);

void			pa(t_info *info);
void			pb(t_info *info);

void			ra(t_info *info);
void			rb(t_info *info);
void			rr(t_info *info);

void			rra(t_info *info);
void			rrb(t_info *info);
void			rrr(t_info *info);

char			**ft_split(char const *s, char c);
char			**ft_free_strs(char **str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_atoi(const char *str, int *result);
int				ft_strcmp(char *s1, char *s2);

void			print_error(void);

#endif
