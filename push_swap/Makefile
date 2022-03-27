# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 20:50:01 by seonhong          #+#    #+#              #
#    Updated: 2021/07/07 22:41:55 by seonhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
INC			= -I includes/push_swap
INC_BONUS	= -I includes/checker
RM			= rm -f

SRCS		= srcs/main.c \
			srcs/push_swap.c \
			srcs/setting_num.c \
			srcs/ft_split.c \
			srcs/ft_string.c \
			srcs/ft_sort.c \
			srcs/print_error.c \
			srcs/operator_s.c \
			srcs/operator_p.c \
			srcs/operator_r.c \
			srcs/operator_rr.c \
			srcs/get_pivot.c \
			srcs/small_arg.c \
			srcs/check_sort.c \
			srcs/ab_to_ab.c

SRCS_BONUS	= bonus/main.c \
			bonus/checker.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c \
			bonus/setting_num.c \
			bonus/ft_split.c \
			bonus/ft_string.c \
			bonus/operator_s.c \
			bonus/operator_r.c \
			bonus/operator_rr.c \
			bonus/operator_p.c \
			bonus/print_error.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_BONUS)
	NAME=checker
else
	OBJ_FILES = $(OBJS)
endif

ifdef WITH_BONUS
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC_BONUS)
else
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

bonus:
	make WITH_BONUS=1 all

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re