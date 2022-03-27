TEST=test.osut
NAME=cub3D
CFLAGS=-Wall -Wextra -Werror
MLXFLAGS=-L./mlx -lmlx -framework OpenGL -framework AppKit
SRCS_NAME=	cub3d.c\
			input.c\
			vector1.c\
			vector2.c\
			logic1.c\
			logic2.c\
			wall.c\
			init.c\
			parse_cub1.c\
			parse_cub2.c\
			parse_cub3.c\
			parse_cub4.c\
			utility1.c\
			utility2.c\
			utility3.c\
			utility_mem.c\
			ray.c\
			lst.c\
			object.c\
			player.c\
			background.c\
			save_bmp.c\
			get_next_line.c\
			get_next_line_utils.c
INCFALGS=-I./mlx -I./includes
SRCS_DIR= ./srcs
SRCS=$(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS_NAME= $(SRCS_NAME:.c=.o)
OBJS_DIR= ./objs
OBJS= $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./mlx all
	@gcc $(CFLAGS) $(MLXFLAGS) $(INCFALGS) $(SRCS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	@gcc $(CFLAGS) $(INCFALGS) -o $@ -c $<

clean:
	@$(MAKE) -C ./mlx clean
	rm -rf ./objs image.bmp

fclean: clean
	@$(MAKE) -C ./mlx clean
	rm -rf ./objs $(NAME)
tclean:
	rm -rf objs $(TEST)

re : fclean all