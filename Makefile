# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/03/14 19:24:19 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit
SRCS = ./main.c
OBJS = $(SRCS:.c=.o)
LFT = -L./libft/ -lft
LMLX = -L./minilibx_macos/ -lmlx
HEAD = -I ./includes/fdf.h

all: $(NAME)

$(NAME):
	@echo "\033[33mCompiling libft.a ...\033[0m"
	@make -s -C ./libft/
	@echo "\033[32mCompiling libft.a done !\033[0m"
	@echo "\033[33mCompiling mlx.a ...\033[0m"
	@make -s -C ./minilibx_macos/
	@echo "\033[32mCompiling mlx.a done !\033[0m"
	@echo "\033[33mCompiling in .o ...\033[0m"
	@gcc $(HEAD) -c $(SRCS)
	@echo "\033[32mCompiling in .o done !\033[0m"
	@echo "\033[33mCompiling fdf ...\033[0m"
	@gcc -o $(NAME) $(OBJS) $(LMLX) $(LFT) $(FRAMEWORK)
	@echo "\033[32mCompiling fdf done !\033[0m"

mc: fclean all clean

clean:
	@echo "\033[31mdeleting all .o ...\033[0m"
	@rm -f $(OBJS)
	@echo "\033[32mThe folder is clean !\033[0m"

fclean:
	@echo "\033[31mDeleting libft.a and all .o ...\033[0m"
	@rm -f $(NAME) $(OBJS)
	@echo "\033[32mThe folder is clean\033[0m"
	@make -s fclean -C ./libft/
	@make -s clean -C ./minilibx_macos/

re: fclean all
