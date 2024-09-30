/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximg_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:00:37 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 14:00:53 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define DST_ROW y_idx * frame->size_line
#define SRC_ROW y_idx * frameset.size_line
#define SRC_COL frame_n * frameset.bpp / 8 * TILE_SIZE

#define DST_OFFSET frame->buff + DST_ROW
#define SRC_OFFSET frameset.buff + SRC_ROW + SRC_COL

#define BYTES_PER_LINE frameset.bpp / 8 * TILE_SIZE

t_error ft_ximg_frame(t_xenv x, t_ximg frameset, t_ximg *frame, size_t frame_n)
{
	int y_idx;
	t_error err;

	err = ft_ximg_setup(x.display, frame, TILE_SIZE, TILE_SIZE);
	if (err)
		return (err);

	y_idx = 0;
	while (y_idx < frame->height)
	{
		ft_memmove(DST_OFFSET, SRC_OFFSET, BYTES_PER_LINE);
		y_idx++;
	}

	return (OK);
}
