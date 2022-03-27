# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 18:16:53 by seonhong          #+#    #+#              #
#    Updated: 2021/06/11 19:53:29 by seonhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INC			= ft_printf.h
LIBFT		= Libft
LIBFT_LIB	= libft.a
AR			= ar rc
RM			= rm -f

SRCS = ft_printf.c \
		ft_pars_spec.c \
		ft_print_c.c \
		ft_print_s.c \
		ft_print_d.c \
		ft_setbuf_d.c \
		ft_print_p.c \
		ft_print_percent.c \
		ft_print_u.c \
		ft_print_x.c \
		ft_setbuf_x.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $^

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all
