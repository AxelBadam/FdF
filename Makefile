NAME = fdf
SRC = main.c controls.c controls_2.c draw.c free.c ft_atoi_base.c init.c parsing.c projection.c rotate.c utils.c
LIBFT = libft
MINILIBX = minilibx_macos
OBJECT = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
OBJDIR = obj
SRCDIR = src

all: obj $(OBJDIR) $(NAME)

bonus: all

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@make -s -C $(MINILIBX)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	@make -s -C $(LIBFT)
	$(CC) $(OBJECT) -framework AppKit -framework OpenGL $(LIBFT)/libft.a $(MINILIBX)/libmlx.a -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)
	make clean -C $(MINILIBX)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
