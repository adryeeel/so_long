/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:10:17 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/29 02:25:14 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_render_space(void *display, t_map map, t_ximg *scene)
{
	t_ximg tex;
	t_error err;
	t_coord coord;

	err = ft_ximgf_setup(display, &tex, BG_IMG_PATH);
	if (err)
		return (err);

	coord = ft_map_search_seq(map, SPACE);

	while (coord.x >= 0)
	{
		ft_render_tile(scene, tex, (t_coord){
			coord.x * TILE_SIZE, 
			coord.y * TILE_SIZE
		});
		coord = ft_map_search_seq(map, SPACE);
	}

	ft_ximg_free(display, tex);
	return (OK);
}
