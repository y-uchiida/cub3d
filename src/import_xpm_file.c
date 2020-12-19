/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_xpm_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:17:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/18 02:24:43 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool		import_xpm_file(t_game *game, t_img *tx, const char *file_path)
{
	int		fd;

	if (ft_check_extension(file_path, "xpm") == false)
		return (put_errors(ERR_NOT_XPMFILE, "import_xpm_file"));
	if ((fd = open(file_path, O_RDONLY)) == -1)
		return (put_errors(ERR_CANT_OPEN_XPMFILE, "import_xpm_file"));
	close(fd);
	tx->ptr = mlx_xpm_file_to_image(game->mlx.ptr, (char *)file_path,
			&(tx->width), &(tx->height));
	if (tx == NULL)
		put_errors(ERR_XMPFILE_READ_FAILED, "import_xpm_file");
	tx->data = mlx_get_data_addr(tx->ptr, &(tx->bpp),
									&(tx->size_line), &(tx->endian));
	if (tx->data == NULL)
		put_errors(ERR_XMPDATA_GET_FAILED, "import_xpm_file");
	return (true);
}
