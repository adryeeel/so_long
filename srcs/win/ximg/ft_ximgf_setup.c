/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximgf_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:20:08 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 23:07:04 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../so_long.h"

static bool ft_file_exists(char *filepath)
{
	int fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (false);

	close(fd);
	return (true);
}

t_error ft_ximgf_setup(void *display, t_ximg *ximg, char *path)
{
	if (!ft_file_exists(path))
		return (ERR_XIMG_FILEPATH);

	ximg->path = ft_strdup(path);
	ximg->id = mlx_xpm_file_to_image(display, path, &ximg->width, &ximg->height);

	if (!ximg->id)
	{
		free(ximg->path);
		return (ERR_XIMG_CREATE);
	}

	ximg->buff = mlx_get_data_addr(ximg->id, &ximg->bpp, &ximg->size_line, &ximg->endian);

	if (!ximg->buff)
		return (ERR_XIMG_DATA);

	return (OK);
}
