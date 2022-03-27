/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:13:52 by seonhong          #+#    #+#             */
/*   Updated: 2021/07/04 19:40:40 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_info
{
	int		*a;
	int		*b;
	int		a_top;
	int		b_top;
	int		size;
}				t_info;

typedef struct	s_count
{
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}				t_count;

typedef struct	s_pivot
{
	int		p1;
	int		p2;
}				t_pivot;

void			push_swap(int argc, char *argv[]);

void			setting_num(t_info *info, int argc, char *argv[]);

void			sa(t_info *info, int flag);
void			sb(t_info *info, int flag);
void			ss(t_info *info);

void			pa(t_info *info);
void			pb(t_info *info);

void			ra(t_info *info, int flag);
void			rb(t_info *info, int flag);
void			rr(t_info *info);

void			rra(t_info *info, int flag);
void			rrb(t_info *info, int flag);
void			rrr(t_info *info);

void			a_to_b(t_info *info, int size);
void			b_to_a(t_info *info, int size);
void			b_to_a_util(t_info *info, t_count *count, \
				t_pivot pivot, int size);
void			a_to_b_util(t_info *info, t_count *count, \
				t_pivot pivot, int size);

char			**ft_split(char const *s, char c);
char			**ft_free_strs(char **str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_atoi(const char *str, int *result);

int				check_sort_a(t_info *info, int size);
int				check_sort_b(t_info *info, int size);

void			ft_sort(int arr[], int size);
void			small_sort_a(t_info *info, int size);
void			small_sort_b(t_info *info, int size);

void			three_arg(t_info *info);
void			four_arg(t_info *info);
void			five_arg(t_info *info);

int				*copy_arr(t_info *info, int size, int flag);
t_pivot			get_pivot(t_info *info, int size, int flag);

void			print_error(void);

#endif
