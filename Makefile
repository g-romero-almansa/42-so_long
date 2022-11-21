# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 12:40:41 by gromero-          #+#    #+#              #
#    Updated: 2022/11/07 16:50:14 by gromero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				ft_check_and_error.c ft_read_and_draw_map.c ft_moves.c ft_end_game.c

OBJ			=	$(SRC:.c = .o)

SRC_BONUS	=	bonus/so_long_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				bonus/ft_check_and_error_bonus.c bonus/ft_read_and_draw_map_bonus.c bonus/ft_moves_bonus.c \
				bonus/ft_end_game_bonus.c

OBJ_BONUS	=	$(SRC_BONUS:.c = .o)

INCMLX		=	./MLX42
LIBMLX		=	libmlx42.a

INCPRINT	=	./printf
LIBPRINT	=	libftprintf.a

INCLIBFT	=	./libft
LIBLIBFT	=	libft.a

EXEC		=	so_long

EXEC_BONUS	=	so_long_bonus

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
LINKS		=	-I include -lglfw -L "/Users/gromero-/.brew/opt/glfw/lib/"

all:		$(EXEC)

$(NAME):	all

$(LIBMLX):
	make -C $(INCMLX)

$(LIBPRINT):
	make -C $(INCPRINT)

$(LIBLIBFT):
	make -C $(INCLIBFT)

$(EXEC):	$(LIBMLX)	$(LIBPRINT) $(LIBLIBFT) $(OBJ)
	$(CC)	$(CFLAGS)	$(LINKS)	$(OBJ)	-o	$(EXEC)	$(INCMLX)/$(LIBMLX) $(INCPRINT)/$(LIBPRINT) $(INCLIBFT)/$(LIBLIBFT)

bonus:		$(LIBMLX)	$(LIBPRINT) $(LIBLIBFT) $(OBJ_BONUS)
	$(CC)	$(CFLAGS)	$(LINKS)	$(OBJ_BONUS)	-o	$(EXEC_BONUS) $(INCMLX)/$(LIBMLX) $(INCPRINT)/$(LIBPRINT) $(INCLIBFT)/$(LIBLIBFT)

clean:
	rm -f $(EXEC) $(EXEC_BONUS)
	make -C MLX42 clean
	make -C printf clean
	make -C libft clean

fclean:
	rm -f $(NAME)
	make -C MLX42 fclean
	make -C printf fclean
	make -C libft fclean

re: clean fclean all

.PHONY: all clean fclean re bonus
