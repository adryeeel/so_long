/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fadeout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:00:56 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/18 12:49:57 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define OFFSET (y * x.scene.size_line) + (z * (x.scene.bpp / 8))

static bool ft_pixel_isblack(char *pixel)
{
	unsigned total;

	total = 0;
	if (pixel[0] == 0)
		total++;

	if (pixel[1] == 0)
		total++;

	if (pixel[2] == 0)
		total++;

	return (total == 3);
}

static void ft_pixel_dim(unsigned char *pixel, int percent)
{
	if (percent < 0 || percent > 100)
		return;

	pixel[0] *= ((100 - percent) / 100.0);
	pixel[1] *= ((100 - percent) / 100.0);
	pixel[2] *= ((100 - percent) / 100.0);
}

bool ft_draw_fadeout(t_xenv x)
{
	int y;
	int z;
	static int dim_amount;

	if (dim_amount >= 15)
	{
		dim_amount = 0;
		return (false);
	}

	y = -1;
	while (++y < x.scene.height)
	{
		z = -1;
		while (++z < x.scene.width)
		{
			if (ft_pixel_isblack(x.scene.buff + OFFSET))
				continue;

			ft_pixel_dim((unsigned char *)x.scene.buff + OFFSET, 24);
		}
	}

	dim_amount++;
	return (true);
}
