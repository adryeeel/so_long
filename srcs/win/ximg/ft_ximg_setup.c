/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximg_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:20:08 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 19:32:23 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_ximg_setup(void *display, t_ximg *ximg, int width, int height)
{
	if (!display || !ximg)
		return (ERR_XIMG_PARAM);

	ximg->path = NULL;
	ximg->width = width;
	ximg->height = height;
	ximg->id = mlx_new_image(display, width, height);

	if (!ximg->id)
		return (ERR_XIMG_CREATE);

	ximg->buff = mlx_get_data_addr(ximg->id, &ximg->bpp, &ximg->size_line, &ximg->endian);

	if (!ximg->buff)
	{
		mlx_destroy_image(display, ximg->id);
		return (ERR_XIMG_DATA);
	}

	return (OK);
}
