/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:23:24 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/13 22:24:47 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_frame(t_xenv x, t_map map, t_mapc comp, size_t frame_n)
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