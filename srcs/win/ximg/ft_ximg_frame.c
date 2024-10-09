/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ximg_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:00:37 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/08 13:49:39 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define FRSET_COL n * frame->size_line
#define FRSET_ROW y * frameset.size_line
#define FRSET_OFF FRSET_ROW + FRSET_COL

#define FRAME_COL 0
#define FRAME_ROW y * frame->size_line
#define FRAME_OFF FRAME_ROW + FRAME_COL

t_error ft_ximg_frame(void *display, t_ximg frameset, t_ximg *frame, size_t n)
{
	int y;
	t_error err;

	err = ft_ximg_setup(display, frame, TILE_SIZE, TILE_SIZE);
	if (err)
		return (err);

	y = -1;
	while (++y < frame->height)
	{
		ft_memmove(
			frame->buff + FRAME_OFF, 
			frameset.buff + FRSET_OFF, 
			frame->size_line
		);
	}

	return (OK);
}
