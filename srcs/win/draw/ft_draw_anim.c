/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:39:11 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 21:02:11 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static t_error ft_draw_frame(t_xenv x, t_map map, t_mapc comp, size_t frame_n)
{
	t_error err;
	t_ximg frame;
	t_coord coord;
	t_ximg frameset;

	if (comp == PATROL)
		frameset = x.patrol;

	if (comp == COLLECTIBLE)
		frameset = x.coll;

	err = ft_ximg_frame(x.display, frameset, &frame, frame_n);
	if (err)
		return (err);

	coord = ft_map_search_seq(map, comp);
	while (coord.x >= 0)
	{
		ft_draw_background(x.display, &frame);
		ft_draw_at(&x.scene, frame, coord);
		coord = ft_map_search_seq(map, comp);
	}

	ft_ximg_free(x.display, frame);
	return (OK);
}

t_error ft_draw_anim(t_xenv x, t_map map)
{
	t_error err;
	static size_t frame_n;

	if (frame_n >= 12)
		frame_n = 0;

	err = ft_draw_frame(x, map, PATROL, frame_n);
	if (err)
		return (ft_error_patrol(err));

	err = ft_draw_frame(x, map, COLLECTIBLE, frame_n);
	if (err)
		return (ft_error_coll(err));

	frame_n++;
	return (OK);
}
