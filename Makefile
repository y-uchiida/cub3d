# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 04:07:40 by yoguchi           #+#    #+#              #
#    Updated: 2020/12/24 01:53:27 by yoguchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L./lib -lft -lmlx -lXext -lX11 -lm -lz

SRCS = \
 main\
 window_init\
 import_cub_file\
 import_xpm_file\
 map_parse\
 map_free\
 map_render\
 map_contain_the_coordinate\
 textures_free\
 set_conf_items\
 register_hooks\
 player_init\
 player_move\
 player_render\
 frame_init\
 image_put_pixel_color\
 color_change_intensity\
 ray_init\
 ray_cast_all\
 ray_cast\
 ray_has_horz_wall_interception\
 ray_has_vert_wall_interception\
 ray_facing_direction\
 ray_free\
 ray_render\
 normalize_angle\
 distance_between_points\
 graphics\
 game_data_update\
 game_exit\
 map_has_wall_at\
 render_fov\
 manipulate_trgb\
 put_errors\

SRCS_PATH = $(addsuffix .c, $(addprefix src/, $(SRCS)))
OBJS = $(SRCS_PATH:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

all: $(NAME)

$(NAME): $(OBJS)
	if [ ! -d lib ]; then \
		mkdir lib; \
	fi
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
	if [ ! -d lib ]; then \
		mkdir lib; \
	fi
	$(MAKE) -C ./src/libft
	cp ./src/libft/libft.a ./lib/
	$(MAKE) clean -C ./src/libft
	$(MAKE) -C ./src/minilibx-linux
	cp ./src/minilibx-linux/libmlx* ./lib/
	$(MAKE) clean -C ./src/minilibx-linux
	$(CC) $(CFLAGS) -g -O0 -fsanitize=address -o $(NAME) $(OBJS) $(LIBS)

.PHONY: all clean fclean re debug
