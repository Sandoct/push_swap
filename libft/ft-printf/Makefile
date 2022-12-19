# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 15:48:50 by gpouzet           #+#    #+#              #
#    Updated: 2022/11/28 19:11:03 by gpouzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c ft_charsize.c ft_digits.c ft_hexa.c ft_toolsprintf.c\

LIBFT = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
		ft_isprint.o ft_toupper.o ft_tolower.o \
		ft_memset.o ft_bzero.o ft_memcpy.o \
		ft_memchr.o ft_memcmp.o ft_memmove.o \
		ft_strlen.o ft_strlcpy.o ft_strlcat.o \
		ft_strchr.o ft_strrchr.o ft_strncmp.o \
		ft_strnstr.o ft_calloc.o ft_strdup.o \
		ft_strjoin.o ft_strtrim.o ft_split.o \
		ft_atoi.o ft_atoipiscine.o ft_itoa.o ft_substr.o \
		ft_strmapi.o ft_striteri.o \
		ft_putchar_fd.o ft_putstr_fd.o \
		ft_putendl_fd.o ft_putnbr_fd.o \

OBJ = $(SRC:.c=.o)

all : $(NAME)

bonus : all

$(NAME) : $(OBJ)
	@make --no-print-directory -C libft
	@ar -x libft/libft.a
	@echo "\\r\033[1;32m[printf compilation completed]"
	@ar rc $(NAME) $(OBJ) $(LIBFT)

%.o : %.c
	@echo -n "\\r\033[1;33m[compiling...]"$<
	@$(CC) -o $@ -c $< $(FLAGS)

clean :
	@rm -rf $(OBJ) $(LIBFT)
	@make clean --no-print-directory -C libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean --no-print-directory -C libft

re : fclean all

.PHONY : all clean fclean re
