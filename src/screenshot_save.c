/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:16:46 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/03 20:28:11 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void				set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int				write_bmp_header(int fd, int file_size, t_game *game)
{
	int					i;
	int					tmp;
	unsigned char		bmp_file_header[54];

	i = 0;
	while (i < 54)
		bmp_file_header[i++] = (unsigned char)(0);
	bmp_file_header[0] = (unsigned char)('B');
	bmp_file_header[1] = (unsigned char)('M');
	set_int_in_char(bmp_file_header + 2, file_size);
	bmp_file_header[10] = (unsigned char)(54);
	bmp_file_header[14] = (unsigned char)(40);
	tmp = game->frame.width;
	set_int_in_char(bmp_file_header + 18, tmp);
	tmp = game->frame.height;
	set_int_in_char(bmp_file_header + 22, tmp);
	bmp_file_header[27] = (unsigned char)(1);
	bmp_file_header[28] = (unsigned char)(24);
	return (!(write(fd, bmp_file_header, 54) < 0));
}

static int				get_color(t_img *frame, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(frame->data
			+ (4 * frame->width * (frame->height - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int				write_bmp_data(int file, t_img *frame, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					y;
	int					x;
	int					color;

	y = 0;
	while (y < frame->height)
	{
		x = 0;
		while (x < frame->width)
		{
			color = get_color(frame, x, y);
			if (write(file, &color, 3) < 0)
				return (false);
			x++;
		}
		if (pad > 0 && write(file, &zero, pad) < 0)
			return (false);
		y++;
	}
	return (true);
}

bool					screenshot_save(t_game *game)
{
	t_img				frame;
	int					file_size;
	int					fd;
	int					pad;

	ft_putendl_fd("saving screenshot...", 1);
	game_data_update(game);
	render_fov(game);
	sprite_render(game);
	minimap_render(game);
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
