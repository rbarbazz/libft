# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:41:38 by rbarbazz          #+#    #+#              #
#    Updated: 2017/12/06 11:34:54 by rbarbazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./src/ft_putchar.c \
      ./src/ft_putstr.c \
      ./src/ft_putendl.c \
      ./src/ft_putnbr.c \
      ./src/ft_putchar_fd.c \
      ./src/ft_putstr_fd.c \
      ./src/ft_putendl_fd.c \
      ./src/ft_putnbr_fd.c \
      ./src/ft_atoi.c \
      ./src/ft_strlen.c \
      ./src/ft_isalpha.c \
      ./src/ft_isdigit.c \
      ./src/ft_isalnum.c \
      ./src/ft_isascii.c \
      ./src/ft_isprint.c \
      ./src/ft_toupper.c \
      ./src/ft_tolower.c \
      ./src/ft_memset.c \
      ./src/ft_bzero.c \
      ./src/ft_memcpy.c \
      ./src/ft_memccpy.c \
      ./src/ft_memmove.c \
      ./src/ft_memchr.c \
      ./src/ft_memcmp.c \
      ./src/ft_strdup.c \
      ./src/ft_strcpy.c \
      ./src/ft_strncpy.c \
      ./src/ft_strcat.c \
      ./src/ft_strncat.c \
      ./src/ft_strchr.c \
      ./src/ft_strrchr.c \
      ./src/ft_strstr.c \
      ./src/ft_strnstr.c \
      ./src/ft_strcmp.c \
      ./src/ft_strncmp.c \
      ./src/ft_memalloc.c \
      ./src/ft_memdel.c \
      ./src/ft_strnew.c \
      ./src/ft_strdel.c \
      ./src/ft_strclr.c \
      ./src/ft_striter.c \
      ./src/ft_striteri.c \
      ./src/ft_strmap.c \
      ./src/ft_strmapi.c \
      ./src/ft_strequ.c \
      ./src/ft_strnequ.c \
      ./src/ft_strsub.c \
      ./src/ft_strjoin.c \
      ./src/ft_strtrim.c \
      ./src/ft_strsplit.c \
      ./src/ft_itoa.c \
      ./src/ft_strlcat.c \
	  ./src/ft_lstnew.c \
	  ./src/ft_lstdelone.c \
	  ./src/ft_lstdel.c

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
