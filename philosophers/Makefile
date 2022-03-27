# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 14:41:17 by seonhong          #+#    #+#              #
#    Updated: 2022/01/04 15:43:16 by seonhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo
CC 			= gcc
CFALGS 		= -Wall -Werror -Wextra
INCS		= ./include/
RM			= rm -f

SRCS		= srcs/main.c \
				srcs/activity.c \
				srcs/threads.c \
				srcs/init.c \
				srcs/utils_philo.c \
				srcs/utils.c

OBJS		= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(CFLAGS) -g -I $(INCS) -pthread $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re