# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 16:16:37 by gpouzet           #+#    #+#              #
#    Updated: 2023/03/07 16:16:37 by gpouzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 	= clang

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

#STK = stack.c stack_utils.c

SRC = main.c push_swap.c push_swap_utils.c homemade.c butterfly.c stack.c stack_utils.c

#SRC += $(STK)

BNS = bonus/main_bonus.c bonus/checker.c stack.c stack_utils.c

#BNS += $(STK)

OBJ	= $(SRC:.c=.o)

OBJB	= $(BNS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make --no-print-directory -C libft
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft -o $(NAME) 
	@echo "\033[1;32m[executable created]"

bonus: $(OBJB)
	@make --no-print-directory -C libft
	@$(CC) $(FLAGS) $(OBJB) -L./libft -lft -o checker
	@echo "\033[1;32m[executable created]"

clean:
	@make fclean --no-print-directory -C libft
	@echo "\033[1;32m[object files cleaned]"
	@rm -rf $(OBJ) $(OBJB)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf checker
	@echo "\033[1;32m[Programe deleted]"

re: fclean all

.PHONY: all clean fclean re bonus
