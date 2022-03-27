# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 13:04:44 by seonhong          #+#    #+#              #
#    Updated: 2021/10/30 11:56:02 by seonhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
CC 			= gcc
CFALGS 		= -Wall -Werror -Wextra
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
LIB_DIR		= ./library/
MLX_DIR		= ./mlx/

LIB_NAME	= ./library/lib_seonhong.a
INCS		= -I includes

SRC			= main.c \
			read_map.c \
			init_game.c \
			init_map.c \
			key_hook.c \
			move.c \
			check_err.c \
			utils.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
LIBS		= $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -l_seonhong -I $(INCS_DIR) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

clean:
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
