SRC = main.c draw.c init.c read_map.c util.c util2.c controls.c atoi_base.c \
rotate.c draw_util.c util3.c mouse.c errors_free.c
OBJ = $(SRC:.c=.o)
CC_FLAGS = -Wall -Wextra -Werror -g
CC = cc
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = fdf
LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CC_FLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT) -o $@

%.o: %.c 
	$(CC) $(CC_FLAGS) -c $<

bonus: all

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean:	clean
	rm -rf $(NAME)	
	make -C libft fclean

re: fclean all
