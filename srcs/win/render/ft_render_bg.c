/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:10:17 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 17:14:15 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_fill_tile(t_ximg t, t_ximg *s, int sx, int sy)
{
	int x;
	int y;
	size_t s_idx;
	size_t t_idx;

	y = 0;
	while (y < t.height)
	{
		x = 0;
		while (x < t.width)
		{
			t_idx = (y * t.size_line) + (x * (t.bpp / 8));
			s_idx = ((sy + y) * s->size_line) + ((sx + x) * (s->bpp / 8));

			s->buff[s_idx] = t.buff[t_idx];
			s->buff[s_idx + 1] = t.buff[t_idx + 1];
			s->buff[s_idx + 2] = t.buff[t_idx + 2];
			s->buff[s_idx + 3] = t.buff[t_idx + 3];
			x++;
		}
		y++;
	}

	return (true);
}

bool ft_render_bg(void *display, t_ximg *scene)
{
	int x;
	int y;
	t_ximg tex;

	if (!ft_ximgf_setup(display, &tex, BG_IMG_PATH))
		return (false);

	y = 0;
	while (y < scene->height)
	{
		x = 0;
		while (x < scene->width)
		{
			ft_fill_tile(tex, scene, x, y);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}

	ft_ximg_free(display, tex);

	return (true);
}
