/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximg_fill_alpha.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:16:33 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 21:00:41 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define PXL_SIZE 4
#define TRANSPARENT 0

#define SRC_PXL_COL x * (src.bpp / 8)
#define SRC_PXL_ROW y * src.size_line

#define DST_PXL_COL (x + dst_p.x) * (dst->bpp / 8)
#define DST_PXL_ROW (y + dst_p.y) * dst->size_line

#define DST_PXL DST_PXL_ROW + DST_PXL_COL
#define SRC_PXL SRC_PXL_ROW + SRC_PXL_COL

void ft_color_print(unsigned char *buff)
{
	unsigned int color;
	
    color = (*buff << 24) |(buff[1] << 16) | (buff[2] << 8) | buff[3];

	printf("0: (%u) | (%x)\n", buff[0], buff[0]);
	printf("1: (%u) | (%x)\n", buff[1], buff[1]);
	printf("2: (%u) | (%x)\n", buff[2], buff[2]);
	printf("3: (%u) | (%x)\n", buff[3], buff[3]);
	
	printf("Color: (%u) | (%x)\n\n", color, color);

}

void ft_ximg_fill_alpha(t_ximg *dst, t_ximg src, t_coord dst_p)
{
	int y;
	int x;

	y = -1;
	while (++y < src.height)
	{
		x = -1;
		while (++x < src.width)
		{
			if ((unsigned char)dst->buff[DST_PXL + 3] != 255)
				continue;

			ft_memmove(dst->buff + DST_PXL, src.buff + SRC_PXL, PXL_SIZE);
		}
	}
}
