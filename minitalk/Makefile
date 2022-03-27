# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 15:05:53 by seonhong          #+#    #+#              #
#    Updated: 2021/09/27 19:17:40 by seonhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
B_SERVER = server_bonus
B_CLIENT = client_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I srcs/
B_INC = -I srcs_bonus/
RM = rm -f

SRCS_SERVER = srcs/server/main.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = srcs/client/main.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_UTILS = srcs/utils/ft_atoi.c \
			srcs/utils/ft_strlen.c \
			srcs/utils/ft_putchar_fd.c \
			srcs/utils/ft_putnbr_fd.c \
			srcs/utils/ft_isdigit.c \
			srcs/utils/ft_error.c
OBJS_UTILS = $(SRCS_UTILS:.c=.o)

B_SRCS_SERVER = srcs_bonus/server/main_bonus.c
B_OBJS_SERVER = $(B_SRCS_SERVER:.c=.o)

B_SRCS_CLIENT = srcs_bonus/client/main_bonus.c
B_OBJS_CLIENT = $(B_SRCS_CLIENT:.c=.o)

B_SRCS_UTILS = srcs_bonus/utils/ft_atoi_bonus.c \
			srcs_bonus/utils/ft_strlen_bonus.c \
			srcs_bonus/utils/ft_putchar_fd_bonus.c \
			srcs_bonus/utils/ft_putnbr_fd_bonus.c \
			srcs_bonus/utils/ft_isdigit_bonus.c \
			srcs_bonus/utils/ft_error_bonus.c
B_OBJS_UTILS = $(B_SRCS_UTILS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC) $(B_INC)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(OBJS_UTILS)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(OBJS_UTILS) $(INC) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(OBJS_UTILS) $(INC) -o $(CLIENT)

bonus: $(B_SERVER) $(B_CLIENT)

$(B_SERVER): $(B_OBJS_SERVER) $(B_OBJS_UTILS)
	$(CC) $(CFLAGS) $(B_OBJS_SERVER) $(B_OBJS_UTILS) $(INC) -o $(B_SERVER)

$(B_CLIENT): $(B_OBJS_CLIENT) $(B_OBJS_UTILS)
	$(CC) $(CFLAGS) $(B_OBJS_CLIENT) $(B_OBJS_UTILS) $(INC) -o $(B_CLIENT)

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_UTILS) $(B_OBJS_SERVER) $(B_OBJS_CLIENT) $(B_OBJS_UTILS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(B_SERVER) $(B_CLIENT)

re: clean all
