/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximg_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:24:02 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 21:55:09 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define TRANSPARENT (char)0xFF000000

#define SRC_ROW_IDX (y * src.size_line)
#define SRC_COL_IDX (x * (src.bpp / 8))

#define DST_ROW_IDX ((dst_p.y + y) * dst->size_line)
#define DST_COL_IDX ((dst_p.x + x) * (dst->bpp / 8))

void ft_ximg_copy(t_ximg *dst, t_ximg src, t_coord dst_p)
{
	int x;
	int y;
	size_t dst_idx;
	size_t src_idx;

	y = 0;
	while (y < src.height)
	{
		x = 0;
		while (x < src.width)
		{
			dst_idx = DST_ROW_IDX + DST_COL_IDX;
			src_idx = SRC_ROW_IDX + SRC_COL_IDX;

			if (src.buff[src_idx] == TRANSPARENT)
			{
				x++;
				continue;
			}

			dst->buff[dst_idx] = src.buff[src_idx];
			dst->buff[dst_idx + 1] = src.buff[src_idx + 1];
			dst->buff[dst_idx + 2] = src.buff[src_idx + 2];
			dst->buff[dst_idx + 3] = src.buff[src_idx + 3];
			x++;
		}
		y++;
	}
}
