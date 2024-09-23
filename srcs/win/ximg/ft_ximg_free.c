/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximg_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:13:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 18:22:16 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_ximg_free(void *display, t_ximg ximg)
{
	int tmp;

	tmp = errno;

	if (!display)
		return;

	if (ximg.id)
		mlx_destroy_image(display, ximg.id);

	if (ximg.path)
		free(ximg.path);

	errno = tmp;
}
