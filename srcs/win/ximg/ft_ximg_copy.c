/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximg_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:24:02 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/07 01:55:36 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define PXL_SIZE 4

#define SRC_PXL_COL x * (src.bpp / 8)
#define SRC_PXL_ROW y * src.size_line

#define DST_PXL_COL (x + dst_p.x) * (dst->bpp / 8)
#define DST_PXL_ROW (y + dst_p.y) * dst->size_line

#define DST_PXL DST_PXL_ROW + DST_PXL_COL
#define SRC_PXL SRC_PXL_ROW + SRC_PXL_COL

void ft_ximg_copy(t_ximg *dst, t_ximg src, t_coord dst_p)
{
	int x;
	int y;

	y = -1;
	while (++y < src.height)
	{
		x = -1;
		while (++x < src.width)
			ft_memmove(dst->buff + DST_PXL, src.buff + SRC_PXL, PXL_SIZE);
	}
}
