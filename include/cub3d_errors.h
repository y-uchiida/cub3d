/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:15:27 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/16 23:32:32 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

# define TEXT_RED "\033[31m"
# define TEXT_RESET "\x1b[m"

# define ERR_MLX_INIT_FAILURE "initialize minilibx failed."
# define ERR_NO_ARG "command line args 1 rquires path to .cub file."
# define ERR_NOT_CUBFILE "command line args 1 is not .cub file."
# define ERR_CANT_OPEN_CUBFILE "given .cub file cannot be opened."
# define ERR_CUBFILE_READ_FAILED "reading a given .cub file failed."
# define ERR_INVALID_RESOL_INPUT "resolution in .cub file is invalid."
# define ERR_MULTIPLE_RESOL_INPUT ".cub file has multiple resolutin input."
# define ERR_DUPLICATE_TEXTURE_INPUT ".cub file has duplicate texture input."
# define ERR_INVALID_COLOR_INPUT "ceil/floor color in .cub file is invalid."
# define ERR_DUPLICATE_COLOR_INPUT ".cub file has duplicate ceil/floor input."
# define ERR_NOT_XPMFILE "given file is not xpm."
# define ERR_CANT_OPEN_XPMFILE "given .xpm file cannot be opened."
# define ERR_XMPFILE_READ_FAILED "reading a given .xpm file failed."
# define ERR_XMPDATA_GET_FAILED "get a .xpm data failed."

#endif
