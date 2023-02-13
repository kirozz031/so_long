# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusezett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:18:18 by lusezett          #+#    #+#              #
#    Updated: 2023/02/13 15:14:14 by lusezett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Wextra -Werror

SRC = ./srcs/so_long.c \
			./srcs/mapcheck.c \
			./srcs/mapcheck_2.c \
			./srcs/map_utils.c \
			./srcs/moves.c \
			./srcs/put_content.c \
			./srcs/get_pos.c \
			./srcs/get_next_line.c \
			./srcs/destroy.c \
			./srcs/handle_things.c \
			./srcs/pathfinder.c \
			./srcs/utils.c \
			./srcs/utils2.c \
			

OBJS = $(SRC:.c=.o)

CC = gcc

RM = rm -rf

INC =   include

LIB = ./minilibx/libmlx_Linux.a -g3 -lXext -lX11 -I ./minilibx/

.c.o:
	$(CC) -I $(INC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	make -C ./minilibx
	$(CC) $(FLAGS) -I $(INC) -o $(NAME) $(OBJS) $(LIB)


clean:
	$(RM) $(OBJS) $(NAME)
	make clean -C ./minilibx

fclean: clean
	$(RM) $(NAME)
	$(RM) ./minilibx/libmlx_Linux.a
	$(RM) ./minilibx/libmlx.a

re: fclean all

.PHONY: all clean fclean re
