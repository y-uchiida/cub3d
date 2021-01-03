/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:15:27 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/04 06:27:16 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_BONUS_H
# define CUB3D_ERRORS_BONUS_H

# define TEXT_RED "\033[31m"
# define TEXT_RESET "\x1b[m"

# define ERR_MLX_INIT_FAILURE "initialize minilibx failed."
# define ERR_NO_ARG "command line args 1 rquires path to .cub file."
# define ERR_INVALID_SECOND_ARG "command line args 2 allows \"--save\" only."
# define ERR_TO_MUCH_ARGS "too much command line args. allows 1 or 2 only."
# define ERR_NOT_CUBFILE "command line args 1 is not .cub file."
# define ERR_CANT_OPEN_CUBFILE "given .cub file cannot be opened."
# define ERR_CUBFILE_READ_FAILED "reading a given .cub file failed."
# define ERR_INVALID_RESOL_INPUT "resolution in .cub file is invalid."
# define ERR_MULTIPLE_RESOL_INPUT ".cub file has multiple resolutin input."
# define ERR_RESOL_TOO_LARGE "resolution in .cub file is too large."
# define ERR_NO_RESOL_SETTING ".cub file has no resolutin input."
# define ERR_DUPLICATE_TEXTURE_INPUT ".cub file has duplicate texture input."
# define ERR_NO_TEXTURE_SETTING ".cub file has few texture input."
# define ERR_INVALID_COLOR_INPUT "ceil/floor color in .cub file is invalid."
# define ERR_DUPLICATE_COLOR_INPUT ".cub file has duplicate ceil/floor input."
# define ERR_NO_COLOR_INPUT ".cub file no ceil/floor input."
# define ERR_INVALID_CONF_PARAM ".cub file has invalid paramater item."
# define ERR_TOO_FEW_COMF_PARAMS ".cub file has too few paramater items."
# define ERR_NO_XPM_FILEPATH "texture param has no filepath."
# define ERR_NOT_XPMFILE "given file is not xpm."
# define ERR_MULTIPLE_XPM_FILEPATH "given 2 more filepath params."
# define ERR_CANT_OPEN_XPMFILE "given .xpm file cannot be opened."
# define ERR_XMPFILE_READ_FAILED "reading a given .xpm file failed."
# define ERR_XMPDATA_GET_FAILED "get a .xpm data failed."
# define ERR_MALLOC_FAILED "malloc() failed."
# define ERR_INVALID_MAP_INPUT "map in .cub file has invalid character."
# define ERR_DUPLICATE_MAP_INPUT "map in .cub file has multiple player char."
# define ERR_MLX_IMAGE_FAILD "create new image data faild."
# define ERR_CANT_OPEN_BMPFILE "failed create screenshot bmp file."
# define ERR_FAILED_WRITE_BMP_HEADER "failed write bmp file header."
# define ERR_WRITE_BMP_COLOR "failed write bmp color."
# define ERR_MAP_TOO_LARGE "given map is too large. must be under 100*100."
# define ERR_MAP_NOT_CLOSED "given map data not closed."
# define ERR_NO_MAP "givn .cub file has no map."
# define ERR_NO_PLAYER "givn .cub file has no player in map."

#endif
