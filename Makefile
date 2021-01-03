# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 04:07:40 by yoguchi           #+#    #+#              #
#    Updated: 2021/01/04 07:00:57 by yoguchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L./lib -lft -lmlx -lXext -lX11 -lm

SRCS = \
 main\
 window_init\
 import_cub_file\
 import_xpm_file\
 bg_colors_set\
 map_parse\
 map_free\
 map_render\
 map_contain_the_coordinate\
 map_closed_check\
 minimap_init\
 minimap_render\
 textures_init\
 textures_free\
 set_conf_items\
 resolution_set\
 register_hooks\
 player_init\
 player_move\
 player_render\
 frame_init\
 frame_free\
 image_put_pixel_color\
 image_get_pixel_color\
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
 sprite_new_item\
 sprite_add_in_map\
 sprites_calc_distance\
 sprites_sort\
 put_sprite_marker\
 sprite_render\
 sprites_free\
 cross_hair_init\
 cross_hair_render\
 cross_hair_free\
 game_data_update\
 game_exit\
 event_hooks_key_close_button\
 event_hooks_mouse\
 map_has_wall_at\
 render_fov\
 manipulate_trgb\
 screenshot_save\
 put_errors\

SRCS_PATH = $(addsuffix .c, $(addprefix src/, $(SRCS)))
OBJS = $(SRCS_PATH:.c=.o)

BONUS_PATH = $(addsuffix _bonus.c, $(addprefix bonus/, $(SRCS)))
BONUS_OBJS = $(BONUS_PATH:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

all: $(NAME)

$(NAME): $(OBJS)
	if [ ! -d lib ]; then \
		mkdir lib; \
	fi
	$(MAKE) -C ./src/libft
	cp ./src/libft/libft.a ./lib/
	$(MAKE) -C ./src/minilibx-linux
	cp ./src/minilibx-linux/libmlx* ./lib/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)


clean:
	$(MAKE) clean -C ./src/libft/
	$(MAKE) clean -C ./src/minilibx-linux
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

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
	$(CC) $(CFLAGS) -g -O0 -o $(NAME) $(OBJS) $(LIBS)

fsanitize: fclean $(OBJS)
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

bonus: $(BONUS_OBJS)
	if [ ! -d lib ]; then \
		mkdir lib; \
	fi
	$(MAKE) -C ./src/libft
	cp ./src/libft/libft.a ./lib/
	$(MAKE) -C ./src/minilibx-linux
	cp ./src/minilibx-linux/libmlx* ./lib/
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(LIBS)


.PHONY: all clean fclean re debug fsanitize bonus
