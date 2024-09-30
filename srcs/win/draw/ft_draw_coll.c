/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_coll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 02:45:01 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:15:44 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_coll(t_xenv x, t_game g, size_t frame_n)
{
	t_error err;
	t_ximg frame;
	t_coord coord;

	err = ft_ximg_frame(x, x.coll, &frame, frame_n);
	if (err)
		return (err);

	err = ft_draw_comp(x, g.map, COLLECTIBLE, BG_IMG_PATH);
	if (err)
	{
		ft_ximg_free(x.display, frame);
		return (ft_error_coll(err));
	}

	coord = ft_map_search_seq(g.map, COLLECTIBLE);
	while (coord.x >= 0)
	{
		ft_ximg_copy(&x.scene, frame, (t_coord){
			coord.x * TILE_SIZE, 
			coord.y * TILE_SIZE
		});
		coord = ft_map_search_seq(g.map, COLLECTIBLE);
	}

	ft_ximg_free(x.display, frame);
	return (OK);
}

