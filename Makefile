# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2017/12/20 13:07:42 by rbarbazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./src/ft_atoi.c \
	  ./src/ft_itoa.c \
	  ./src/boolean/ft_isalpha.c \
	  ./src/boolean/ft_isdigit.c \
	  ./src/boolean/ft_isalnum.c \
	  ./src/boolean/ft_isascii.c \
	  ./src/boolean/ft_isprint.c \
	  ./src/display/ft_putchar.c \
	  ./src/display/ft_putendl.c \
	  ./src/display/ft_putnbr.c \
	  ./src/display/ft_putstr.c \
	  ./src/display/ft_putchar_fd.c \
	  ./src/display/ft_putstr_fd.c \
	  ./src/display/ft_putendl_fd.c \
	  ./src/display/ft_putnbr_fd.c \
	  ./src/mem/ft_memset.c \
	  ./src/mem/ft_bzero.c \
	  ./src/mem/ft_memdel.c \
	  ./src/mem/ft_memcpy.c \
	  ./src/mem/ft_memccpy.c \
	  ./src/mem/ft_memmove.c \
	  ./src/mem/ft_memchr.c \
	  ./src/mem/ft_memcmp.c \
	  ./src/mem/ft_memalloc.c \
	  ./src/lists/ft_lstnew.c \
	  ./src/lists/ft_lstdelone.c \
	  ./src/lists/ft_lstadd.c \
	  ./src/lists/ft_lstdel.c \
	  ./src/lists/ft_lstiter.c \
	  ./src/strings/ft_strlen.c \
	  ./src/strings/ft_strcat.c \
	  ./src/strings/ft_strncat.c \
	  ./src/strings/ft_strdup.c \
	  ./src/strings/ft_strcpy.c \
	  ./src/strings/ft_strncpy.c \
	  ./src/strings/ft_strstr.c \
	  ./src/strings/ft_strcmp.c \
	  ./src/strings/ft_strncmp.c \
	  ./src/strings/ft_strnstr.c \
	  ./src/strings/ft_strchr.c \
	  ./src/strings/ft_strnew.c \
	  ./src/strings/ft_strrchr.c \
	  ./src/strings/ft_strdel.c \
	  ./src/strings/ft_strclr.c \
	  ./src/strings/ft_striter.c \
	  ./src/strings/ft_striteri.c \
	  ./src/strings/ft_strmap.c \
	  ./src/strings/ft_strlcat.c \
	  ./src/strings/ft_strmapi.c \
	  ./src/strings/ft_strequ.c \
	  ./src/strings/ft_strnequ.c \
	  ./src/strings/ft_strsub.c \
	  ./src/strings/ft_strjoin.c \
	  ./src/strings/ft_strtrim.c \
	  ./src/strings/ft_strsplit.c \
	  ./src/strings/ft_toupper.c \
	  ./src/strings/ft_tolower.c \
	  ./src/strings/ft_strjoinchar.c \
	  ./src/get_next_line.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I ./includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
