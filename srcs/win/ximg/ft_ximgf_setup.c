/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximgf_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:20:08 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 16:54:00 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_ximgf_setup(void *display, t_ximg *ximg, char *path)
{
	ximg->path = ft_strdup(path);
	
	if (!ximg->path)
		return (false);

	ximg->id = mlx_xpm_file_to_image(display, path, &ximg->width, &ximg->height);

	if (!ximg->id)
	{
		ft_ximg_free(display, *ximg);
		return (false);
	}

	ximg->buff = mlx_get_data_addr(ximg->id, &ximg->bpp, &ximg->size_line, &ximg->endian);

	if (!ximg->buff)
	{
		ft_ximg_free(display, *ximg);
		return (false);
	}

	return (true);
}
