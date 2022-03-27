# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 22:15:25 by seonhong          #+#    #+#              #
#    Updated: 2021/11/24 23:45:42 by jayi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell
CC 			= gcc
# CC 			= gcc -g3 -fsanitize=address
CFALGS 		= -Wall -Werror -Wextra
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
LIB_DIR		= ./library/

LIB_NAME	= ./library/lib_seonhong.a
INCS		= -I includes

# 인텔 맥 ( 클러스터 PC X )
# READLINE_LIB 	= -lreadline -L/usr/local/opt/readline/lib
# READLINE_INC	= -I/usr/local/opt/readline/include

# 인텔 맥 ( 클러스터 PC O )
# READLINE_LIB 	= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
# READLINE_INC	= -I /Users/$(USER)/.brew/opt/readline/include

# M1 맥 ( 클러스터 PC X )
READLINE_LIB	= -lreadline -L/opt/homebrew/opt/readline/lib
READLINE_INC	= -I/opt/homebrew/opt/readline/include

SRC			=	main.c\
				builtins/ft_cd.c\
				builtins/ft_env.c\
				builtins/ft_pwd.c\
				builtins/ft_echo.c\
				builtins/ft_exit.c\
				builtins/ft_unset.c\
				builtins/ft_export.c\
				tools/find_value_in_envs.c\
				tools/envs.c\
				tools/init_envs.c\
				tools/free_strs.c\
				tools/read_input.c\
				tools/remove_char.c\
				tools/extract_key.c\
				tools/ft_strjoin_char.c\
				tools/ft_strjoin_ref.c\
				tools/ft_isdigit_str.c\
				signal/signal.c\
				parser/ft_split_ms.c\
				parser/check_input.c\
				parser/normalize_input.c\
				parser/normalize_inputs.c\
				execute/execute.c\
				execute/exec_builtins.c\
				redirect/redepi.c\
				redirect/redirect.c\
				error/print_error.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
LIBS		= $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(READLINE_INC) -I $(INCS_DIR) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJS) $(READLINE_LIB) $(READLINE_INC) -L $(LIB_DIR) -l_seonhong -I $(INCS_DIR)

clean:
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all