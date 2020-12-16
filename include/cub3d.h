/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:59:58 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/16 23:27:45 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/extensions/XShm.h>
# include <math.h>
# include <limits.h>
# include <float.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "./cub3d_errors.h"
# include "./libft.h"
# include "./mlx.h"

# define PI 3.14159265
# define TWO_PI 6.28318530

# define TILE_SIZE 64
# define MINIMAP_SCALE_FACTOR 0.2

/*
 ** define colors
*/
# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

typedef	uint32_t	t_color;

typedef struct		s_mlx_window
{
	void			*ptr;
	int				width;
	int				height;
	int				max_width;
	int				max_height;
}					t_mlx_window;

typedef	struct		s_mlx
{
	void			*ptr;
	t_mlx_window	window;
}					t_mlx;

typedef struct		s_map
{
	char			**map;
	t_color			ceil_color;
	t_color			floor_color;
}					t_map;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_texture
{
	t_img			noth_wall;
	t_img			south_wall;
	t_img			east_wall;
	t_img			west_wall;
	t_img			sprite;
}					t_texture;

typedef struct		s_player
{
	float			x;
	float			y;
	float			rotation_angle;
	float			move_speed;
	float			turn_speed;
	int				move_direction;
	int				turn_direction;
}					t_player;

typedef struct 		s_ray
{
	float			angle;
	float			wall_hit_x;
	float			wall_hit_y;
	float			distance;
	int				wall_hit_vertical;
	bool			is_facing_down;
	bool			is_facing_right;
	int				wall_hit_content;
}					t_ray;


typedef struct		s_rays
{
	int				num;
	t_ray			*ray;
	float			fov_angle;
}					t_rays;


/*
 ** contain all structures
*/
typedef struct		s_game
{
	bool			running;
	t_mlx			mlx;
	t_map			map;
	t_texture		texture;
	t_player		player;
	t_rays			rays;
}					t_game;

bool				window_init(t_game *game);
bool				import_cub_file(t_game *game, char *file_path);
bool				import_xpm_file(t_game *game, t_img *tex,
											const char *file_path);
bool				map_parse(t_game *game, const char *line);
bool				set_conf_items(t_game *game, const char **splits);
bool				register_hooks(t_game *game);
bool				player_init(t_game *game);
void				player_move(t_game *game);
bool				ray_init(t_game *game);
bool				ray_cast_all(t_game *game);
int					game_data_update(t_game *game);
void				game_exit(t_game *game);
bool				map_has_wall_at(float x, float y);
void				render_image(t_game *game);
t_color					create_trgb(int t, int r, int g, int b);
int					get_t(t_color trgb);
int					get_r(t_color trgb);
int					get_g(t_color trgb);
int					get_b(t_color trgb);
bool				put_errors(char *err);
void				put_error_details(char *func_name);
#endif
