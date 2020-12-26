/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:16:46 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/27 03:26:15 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// static void				set_int_in_char(unsigned char *start, int value)
// {
// 	start[0] = (unsigned char)(value);
// 	start[1] = (unsigned char)(value >> 8);
// 	start[2] = (unsigned char)(value >> 16);
// 	start[3] = (unsigned char)(value >> 24);
// }

// static int				get_color(t_img *frame, int x, int y)
// {
// 	int					rgb;
// 	int					color;

// 	color = *(int*)(frame->data
// 			+ (4 * (int)frame->width * ((int)frame->height - 1 - y))
// 			+ (4 * x));
// 	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
// 	return (rgb);
// }

// static bool				write_bmp_header(int fd, int file_size, t_game *game)
// {
// 	int					i;
// 	unsigned char		bmp_file_header[54];

// 	i = 0;
// 	while (i < 54)
// 		bmp_file_header[i++] = (unsigned char)(0);
// 	bmp_file_header[0] = (unsigned char)('B');
// 	bmp_file_header[1] = (unsigned char)('M');
// 	set_int_in_char(bmp_file_header + 2, file_size);
// 	bmp_file_header[10] = (unsigned char)(54);
// 	bmp_file_header[14] = (unsigned char)(40);
// 	set_int_in_char(bmp_file_header + 18, game->mlx.window.width);
// 	set_int_in_char(bmp_file_header + 22, game->mlx.window.height);
// 	bmp_file_header[27] = (unsigned char)(1);
// 	bmp_file_header[28] = (unsigned char)(24);
// 	if (!(write(fd, bmp_file_header, 54) < 0) == false)
// 		return (put_errors(ERR_FAILED_WRITE_BMP_HEADER, "write_bmp_header"));
// 	return (true);
// }

// static bool				write_bmp_data(int fd, t_img *frame, int pad)
// {
// 	const unsigned char	zero[3] = {0, 0, 0};
// 	int					x;
// 	int					y;
// 	t_color				color;

// 	x = 0;
// 	while (x < (int)frame->width)
// 	{
// 		y = 0;
// 		while (y < (int)frame->height)
// 		{
// 			color = get_color(frame, y, x);
// 			if (write(fd, &color, 3) < 0)
// 				return (put_errors(ERR_WRITE_BMP_COLOR, "write_bmp_data"));
// 			if (pad > 0 && write(fd, &zero, pad) < 0)
// 				return (put_errors(ERR_WRITE_BMP_COLOR, "write_bmp_data"));
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (true);
// }

static void
	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int
	write_bmp_header(int fd, int filesize, t_game *game)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	// tmp = game->window.size.x;
	tmp = game->mlx.window.width;
	set_int_in_char(bmpfileheader + 18, tmp);
	// tmp = game->window.size.y;
	tmp = game->mlx.window.height;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int
	get_color(t_img *w, int x, int y)
{
	int	rgb;
	int	color;


	// color = *(int*)(w->screen.ptr
	color = *(int*)(w->data
			// + (4 * (int)w->size.x * ((int)w->size.y - 1 - y))
			+ (4 * (int)w->width * ((int)w->height - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);

	// t_color trgb;
	// trgb = image_get_pixel_color(x, y, w);
	// printf("frame[%d, %d] trgb: %x, rgb: %x\n", x, y, (trgb & 0x00FFFFFF), rgb);

	return (rgb);
}

static int
	// write_bmp_data(int file, t_window *w, int pad)
	write_bmp_data(int file, t_img *w, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	// while (i < (int)w->size.y)
	while (i < (int)w->height)
	{
		j = 0;
		// while (j < (int)w->size.x)
		while (j < (int)w->width)
		{
			color = get_color(w, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

bool					screenshot_save(t_game *game)
{
	t_img				frame;
	int					file_size;
	int					fd;
	int					pad;

	player_move(game);
	ray_cast_all(game);
	render_fov(game);
	map_render(game);
	ray_render(game);
	player_render(game);
	frame = game->frame;
	pad = (4 - ((int)frame.width * 3) % 4) % 4;
	file_size = 54 + (3 * ((int)frame.width + pad) * (int)frame.height);
	if ((fd = open("screen_shot.bmp",
					O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)) < 0)
		return (put_errors(ERR_CANT_OPEN_BMPFILE, "screenshot_save"));
	if (write_bmp_header(fd, file_size, game) == false)
		return (false);
	if (write_bmp_data(fd, &frame, pad) == false)
		return (false);
	close(fd);
	game_exit(game);
	return (true);
}