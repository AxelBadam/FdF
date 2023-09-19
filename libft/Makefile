# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 17:46:52 by atuliara          #+#    #+#              #
#    Updated: 2023/03/21 17:17:09 by atuliara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c \
ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memchr.c \
ft_putstr_fd.c	ft_strlen.c ft_toupper.c ft_calloc.c ft_memcmp.c \
ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c ft_strchr.c \
ft_strncmp.c ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c \
ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c ft_isdigit.c \
ft_putchar_fd.c	ft_strjoin.c ft_strtrim.c ft_isprint.c ft_atoi_error.c \
ft_hex.c ft_print_p.c ft_printf_utils.c ft_printf.c ft_uitoa.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = *.o

FLAGS =-Wall -Werror -Wextra

OPTIONS =-c -I.

all: $(NAME)

$(NAME):
	cc $(FLAGS) $(OPTIONS) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
