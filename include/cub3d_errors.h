/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:15:27 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/13 23:55:36 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

# define TEXT_RED "\033[31m"
# define TEXT_RESET "\x1b[m"

# define ERR_NO_ARG "command line args 1 rquires path to .cub file."
# define ERR_NOT_CUBFILE "command line args 1 is not .cub file."
# define ERR_CANT_OPEN_CUBFILE "given .cub file cannot be opened."
# define ERR_CUBFILE_READ_FAILED "reading a given .cub file failed."
# define INVALID_RESOLUTION_INPUT "resolution in .cub file is invalid."
# define MULTIPLE_RESOLUTION_INPUT ".cub file has multiple resolutin input."

#endif
