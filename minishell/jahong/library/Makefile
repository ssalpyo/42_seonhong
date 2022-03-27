# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 15:59:08 by seonhong          #+#    #+#              #
#    Updated: 2021/11/22 23:03:08 by jayi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lib_seonhong.a
CC			= gcc
CFLAG		= -Wall -Wextra -Werror
RM			= rm -f

INC_DIR		= includes
LIBFT_DIR	= srcs/libft
GNL_DIR		= srcs/get_next_line

LIBFT		= ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strchr.c \
			ft_strschr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

GNL			= get_next_line.c \
			get_next_line_utils.c

all: $(NAME)

$(NAME): libft gnl

%.o: %.c
		@$(CC) $(CFLAGS) -c -o $@ $^
		@ar -rcs $(NAME) $@

libft: $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
gnl: $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

clean:
		@$(RM) $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
		@$(RM) $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

fclean: clean
		@$(RM) $(NAME)

re: fclean all
