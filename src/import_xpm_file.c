/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_xpm_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:17:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/30 23:40:28 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	check_xpm_file_open(const char *file_path)
{
	int	fd;

	if (ft_check_extension(file_path, "xpm") == false)
		return (put_errors(ERR_NOT_XPMFILE, "import_xpm_file"));
	if ((fd = open(file_path, O_RDONLY)) == -1)
		return (put_errors(ERR_CANT_OPEN_XPMFILE, "import_xpm_file"));
	close(fd);
	return (true);
}

bool		import_xpm_file(t_game *game, t_img *tx, const char *file_path)
{
	void	*img_ptr;
	char	*data_ptr;

	if ((check_xpm_file_open(file_path)) == false)
		return (false);
	img_ptr = mlx_xpm_file_to_image(game->mlx.ptr, (char *)file_path,
			&(tx->width), &(tx->height));
	if (img_ptr == NULL)
		return (put_errors(ERR_XMPFILE_READ_FAILED, "import_xpm_file"));
	data_ptr = mlx_get_data_addr(img_ptr, &(tx->bpp),
									&(tx->size_line), &(tx->endian));
	if (data_ptr == NULL)
	{
		mlx_destroy_image(game->mlx.ptr, img_ptr);
		put_errors(ERR_XMPDATA_GET_FAILED, "import_xpm_file");
	}
	tx->ptr = img_ptr;
	tx->data = data_ptr;
	return (true);
}
