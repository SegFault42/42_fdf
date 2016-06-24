# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/06/24 17:54:59 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[48;5;196m
SKIN = \033[0m\033[48;5;223m
BROWN = \033[48;5;88m
BLUE = \033[48;5;21m
YELLOW = \033[48;5;226m
END = \033[0m

NAME = fdf
FLAG = -Wall -Wextra -Werror -Ofast
FRAMEWORK = -framework OpenGL -framework AppKit
OBJS = ./main.o ./parsing.o ./print_point.o ./bresenham.o ./count_coord.o \
		./key_hook.o ./menu.o ./event.o ./norme.o
LFT = -L./libft/ -lft
LMLX = -L./minilibx_macos/ -lmlx
HEAD = -I ./includes/fdf.h
INCLUDE = ./includes/fdf.h

VPATH = sources/

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE) Makefile
	@echo "\033[33mCompiling libft.a ...\033[0m"
	@make -s -C ./libft/
	@echo "\033[32mCompiling libft.a done !\033[0m"
	@echo "\033[33mCompiling mlx.a ...\033[0m"
	@make -s -C ./minilibx_macos/
	@echo "\033[32mCompiling mlx.a done !\033[0m"
	@echo "\033[33mCompiling in .o ...\033[0m"
	@echo "\033[32mCompiling in .o done !\033[0m"
	@echo "\033[33mCompiling fdf ...\033[0m"
	@gcc $(FLAG) -o $(NAME) $(OBJS) $(LMLX) $(LFT) $(FRAMEWORK)
	@echo "\033[32mCompiling fdf done !\033[0m"
	@make MARIO

%.o : %.c 
		@gcc -c $(FLAG) $(HEAD) $< -o $@

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

FDF : clean
	@rm -f $(NAME)
	@gcc $(HEAD) -c $(SRCS)
	@gcc -o $(NAME) $(FLAG) $(OBJS) $(LMLX) $(LFT) $(FRAMEWORK)
	@echo "\033[32mCompiled !\033[0m"
	@make MARIO

MARIO :
	@echo "$(END)              $(RED)          $(END)    $(SKIN)      $(END)    $(END)"
	@echo "$(END)            $(RED)                  $(SKIN)    $(END)    $(END)"
	@echo "$(END)            $(BROWN)      $(SKIN)    $(END)  $(SKIN)  $(END)  $(RED)      $(END)    $(END)"
	@echo "$(END)          $(BROWN)  $(SKIN)  $(BROWN)  $(SKIN)      $(END)  $(SKIN)      $(RED)    $(END)    $(END)"
	@echo "$(END)          $(BROWN)  $(SKIN)  $(BROWN)    $(SKIN)      $(END)  $(SKIN)      $(RED)  $(END)    $(END)"
	@echo "$(END)          $(BROWN)    $(SKIN)        $(END)        $(RED)  $(END)      $(END)"
	@echo "$(END)              $(SKIN)              $(RED)    $(END)      $(END)"
	@echo "$(END)  $(SKIN)      $(RED)        $(BLUE)  $(RED)      $(BLUE)  $(RED)    $(END)    $(BROWN)  $(END)  $(END)"
	@echo "$(END)  $(SKIN)      $(RED)          $(BLUE)  $(RED)      $(BLUE)  $(END)    $(BROWN)    $(END)  $(END)"
	@echo "$(END)    $(SKIN)  $(END)      $(RED)      $(BLUE)        $(YELLOW)  $(BLUE)    $(BROWN)    $(END)  $(END)"
	@echo "$(END)              $(BLUE)      $(YELLOW)  $(BLUE)          $(BROWN)    $(END)  $(END)"
	@echo "$(END)          $(BROWN)    $(BLUE)                  $(BROWN)    $(END)  $(END)"
	@echo "$(END)        $(BROWN)      $(BLUE)            $(END)            $(END)"
	@echo "$(END)        $(BROWN)    $(END)                          $(END)"
