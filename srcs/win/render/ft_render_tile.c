/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_tile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:24:02 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 18:17:21 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define TILE_ROW_IDX (y * tile.size_line)
#define TILE_COL_IDX (x * (tile.bpp / 8))

#define DST_ROW_IDX ((dst_p.y + y) * dst->size_line)
#define DST_COL_IDX ((dst_p.x + x) * (dst->bpp / 8))

void ft_render_tile(t_ximg* dst, t_ximg tile, t_coord dst_p)
{
	int x;
	int y;
	size_t dst_idx;
	size_t tile_idx;

	y = 0;
	while (y < tile.height)
	{
		x = 0;
		while (x < tile.width)
		{
			dst_idx = DST_ROW_IDX + DST_COL_IDX;
			tile_idx = TILE_ROW_IDX + TILE_COL_IDX;

			dst->buff[dst_idx] = tile.buff[tile_idx];
			dst->buff[dst_idx + 1] = tile.buff[tile_idx + 1];
			dst->buff[dst_idx + 2] = tile.buff[tile_idx + 2];
			dst->buff[dst_idx + 3] = tile.buff[tile_idx + 3];
			x++;
		}
		y++;
	}
}
