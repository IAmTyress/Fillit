# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzina <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 12:09:39 by kzina             #+#    #+#              #
#    Updated: 2019/06/27 15:58:13 by rrosaura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra -I libft/

SRCS = *.c

LIBFT = libft/libft.a

OBJ = $(SRCS:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): $(SRCS)
	    @gcc -c $(FLAGS) $(SRCS)

$(LIBFT):
	    @make -C libft

$(NAME): $(LIBFT) $(OBJ)
	    @gcc $(OBJ) $(LIBFT) -o $(NAME)
		@echo "\033[01;33m✓ \033[0m\033[01;32mCompiled Executable(Binary)\033[0m\033[01;33m ✓\033[0m"

clean:
	    @rm -f $(OBJ)
		@make -C libft clean
		@echo "\033[01;33mメ\033[0m\033[1;32m Removed Object Files \033[0m\033[01;33mメ\033[0m"

fclean: clean
	    @rm -f $(NAME)
		@make -C libft fclean
		@echo "\033[01;31mメ\033[0m\033[1;32m Removed Binary File  \033[0m\033[01;31mメ\033[0m"

re: fclean all
