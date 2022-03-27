/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:47:24 by seonhong          #+#    #+#             */
/*   Updated: 2021/06/11 22:37:17 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_spec
{
	int	minus;
	int	zero;
	int width;
	int precision;
	int errno;
}				t_spec;

typedef struct	s_size
{
	int	is_zero_num;
	int	is_zero_prec;
	int	length;
}				t_size;

typedef struct	s_box
{
	char	*buff;
	char	*start;
	int		temp;
	t_size	size;
}				t_box;

int				ft_printf(const char *format, ...);

t_spec			pars_spec(const char *str, int length, char format, va_list ap);
t_spec			init_spec(void);
int				pars_flag(int c, t_spec *spec);
void			pars_width(const char **str, t_spec *spec, va_list ap);
void			pars_precision(const char **str, t_spec *spec, va_list ap);

int				ft_print_c(t_spec spec, va_list ap);
int				ft_print_s(t_spec spec, va_list ap);
void			ft_bufset_s(t_spec spec, int len_buff, char *str, char *buff);
int				ft_print_p(t_spec spec, va_list ap);
char			*ft_getaddress_p(void *p, t_spec *spec);
int				ft_getaddress_size_p(long long address, t_spec spec);
int				ft_print_percent(t_spec spec);
int				ft_print_d(t_spec spec, va_list ap);
int				ft_get_numsize_d(long long num, t_spec spec);
char			*ft_setbuf_d(long long arg, int bufsize, \
				int length, t_spec spec);
void			ft_setsign_d(long long num, char **buff, \
				t_spec spec, char *start);
void			ft_setnum_d(long long num, char *tail, t_spec spec);
int				ft_print_u(t_spec spec, va_list ap);
int				ft_print_x(t_spec spec, va_list ap);
int				ft_print_upper_x(t_spec spec, va_list ap);
t_size			ft_get_numsize_x(long long num, t_spec spec);
t_size			init_size(void);
int				ft_get_bufsize_x(t_spec spec, int length);
char			*ft_setbuf_x(long long arg, int bufsize, \
				int isupper, t_spec spec);
void			ft_setnum_x(long long num, char *tail, \
				int isupper, t_spec spec);

#endif
