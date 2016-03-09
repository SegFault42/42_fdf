# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/03/09 13:25:09 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft

FLAG = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

SRC = ./sources/main.c

COMPIL_LIB = make

OBJS = $(SRC:.c=.o)

HEAD = ./libft/libft.a

all: $(NAME)

$(NAME):
	@echo "\033[33mCompiling libft.a ...\033[0m"
	@make -s -C ./libft/
	@echo "\033[36mCompiling libft.a done !\033[0m"
	@echo "\033[33mCompiling fdf in .o ...\033[0m"
	@gcc -c $(SRC)
	@echo "\033[36mCompiling fdf in .o done !\033[0m"
	@gcc -o $(NAME) $(SRC) $(FLAG) $(HEAD)
	@echo "\033[33mCompiling fdf ...\033[0m"
	@echo "\033[36mCompiling fdf done !\033[0m"

mc: fclean all clean

clean:
	@echo "\033[31mdeleting all .o ...\033[0m"
	@rm -f $(OBJS)
	@echo "\033[32mThe folder is clean !\033[0m"

#fclean ne supprime pas les .o a la racine du dossier
fclean:
	@echo "\033[31mDeleting libft.a and all .o ...\033[0m"
	@rm -f $(NAME) $(OBJS)
	@echo "\033[32mThe folder is clean\033[0m"
	@make -s fclean -C ./libft/

re: fclean all
