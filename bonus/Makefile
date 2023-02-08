# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 11:00:40 by gpouzet           #+#    #+#              #
#    Updated: 2023/02/06 14:40:46 by gpouzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAGS = -Wall -Wextra -Werror 

NAME = checker

SRC = main.c checker.c ../stack.c ../stack_utils.c

OBJ	= $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make --no-print-directory -C ../libft
	@$(CC) $(FLAGS) $(OBJ) -L../libft -lft -o $(NAME) 
	@echo "\033[1;32m[executable created]"

clean:
	@make fclean --no-print-directory -C ../libft
	@echo "\033[1;32m[object files cleaned]"
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) 
	@echo "\033[1;32m[Programe deleted]"

re: fclean all

.PHONY: all clean fclean re
