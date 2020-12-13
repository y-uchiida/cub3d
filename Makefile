# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 04:07:40 by yoguchi           #+#    #+#              #
#    Updated: 2020/12/13 23:05:31 by yoguchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
LIBS = -L./lib -lft -lmlx -lXext -lX11 -lm -lz

SRCS = \
 main\
 window_init\
 import_cub_file\
 map_parse\
 set_conf_items\
 register_hooks\
 player_init\
 player_move\
 ray_init\
 ray_cast_all\
 game_data_update\
 game_exit\
 render_image\
 put_errors\
 put_error_details

SRCS_PATH = $(addsuffix .c, $(addprefix src/, $(SRCS)))
OBJS = $(SRCS_PATH:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./src/libft
	cp ./src/libft/libft.a ./lib/
	$(MAKE) clean -C ./src/libft
	$(MAKE) -C ./src/minilibx-linux
	cp ./src/minilibx-linux/libmlx* ./lib/
	$(MAKE) clean -C ./src/minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)


clean:
	$(MAKE) clean -C ./src/libft/
	$(MAKE) clean -C ./src/minilibx-linux
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./src/libft
	$(MAKE) clean -C ./src/minilibx-linux
	rm -rf ./lib/*
	rm -rf $(NAME)

re: fclean all

debug: fclean $(OBJS)
	$(MAKE) -C ./src/libft
	cp ./src/libft/libft.a ./lib/
	$(MAKE) clean -C ./src/libft
	$(MAKE) -C ./src/minilibx-linux
	cp ./src/minilibx-linux/libmlx* ./lib/
	$(MAKE) clean -C ./src/minilibx-linux
	$(CC) $(CFLAGS) -g -fsanitize=address -o $(NAME) $(OBJS) $(LIBS)

run:	
	./$(NAME)

.PHONY: all clean fclean re debug run