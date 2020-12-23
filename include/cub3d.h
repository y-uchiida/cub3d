/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:59:58 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/23 11:42:38 by yoguchi          ###   ########.fr       */
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
# define FOV_ANGLE (60 * (PI / 180))

# define TILE_SIZE 1000
# define MINIMAP_SCALE_FACTOR 0.2

# define TABINDEX_X 0
# define TABINDEX_Y 1

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
	int				rows;
	int				cols;
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
	t_img			wall_no;
	t_img			wall_so;
	t_img			wall_we;
	t_img			wall_ea;
	t_img			sprite;
}					t_texture;

typedef struct		s_player
{
	float			x;
	float			y;
	int				initial_x;
	int				initial_y;
	float			rotation_angle;
	float			move_speed;
	float			turn_speed;
	int				move_direction;
	int				turn_direction;
}					t_player;

typedef struct 		s_ray
{
	float			angle;
	float			wall_intercept_x;
	float			wall_intercept_y;
	float			dist;
	char			wall_hit_content;
	bool			wall_hit_vertical;
	bool			is_facing_down;
	bool			is_facing_right;
	bool			has_horz_interception;
	float			horz_wall_intercept_x;
	float			horz_wall_intercept_y;
	float			horz_wall_dist;
	char			horz_wall_content;
	bool			has_vert_interception;
	float			vert_wall_intercept_x;
	float			vert_wall_intercept_y;
	float			vert_wall_dist;
	char			vert_wall_content;
}					t_ray;

typedef struct		s_rays
{
	int				num;
	t_ray			**ray;
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
	t_img			frame;
}					t_game;

typedef struct 		s_projection
{		
	float			wall_height;
	float			perp_dist;
	int				wall_strip_height;
	int				wall_top_px;
	int				wall_bottom_px;
	t_img			*tex;
	t_color			texture_px_color;
	int				tex_offset_x;
	int				tex_offset_y;
	int				distance_from_top;
}					t_projection;

bool				window_init(t_game *game);
bool				import_cub_file(t_game *game, char *file_path);
bool				import_xpm_file(t_game *game, t_img *tex,
											const char *file_path);
bool				map_parse(t_game *game, char *line);
bool				map_free(char **map);
bool				map_contain_the_coordinate(float x, float y, t_map map);
void				textures_free(t_game *game);
bool				set_conf_items(t_game *game, const char **splits);
bool				register_hooks(t_game *game);
bool				player_init(t_game *game);
void				player_move(t_game *game);
bool				frame_init(t_game *game);
void				image_put_pixel_color(t_img *img,
											int x, int y, t_color color);
void				color_change_intensity(t_color *color, float change_rate);
bool				ray_init(t_game *game);
bool				ray_cast_all(t_game *game);
void				ray_cast(t_game *game, float ray_angle, int strip_id);
void				ray_has_horz_wall_interception(t_ray *ray, t_player player,
									t_map map, float ray_angle);
void				ray_has_vert_wall_interception(t_ray *ray, t_player player,
									t_map map, float ray_angle);
void				ray_facing_direction(t_ray *ray, float ray_angle);
void				ray_free(t_game *game);
void				normalize_angle(float *angle);
float				distance_between_points(float x1, float y1,
											float x2, float y2);
int					game_data_update(t_game *game);
void				game_exit(t_game *game);
bool				map_has_wall_at(float x, float y, t_map *map);
void				render_fov(t_game *game);
t_color				create_trgb(int t, int r, int g, int b);
int					get_t(t_color trgb);
int					get_r(t_color trgb);
int					get_g(t_color trgb);
int					get_b(t_color trgb);
bool				put_errors(char *err, char *func_name);
#endif
