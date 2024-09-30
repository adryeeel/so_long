/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:48:22 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 00:29:52 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_comp(t_xenv x, t_map map, t_mapc comp, char *tex_path)
{
	t_ximg tex;
	t_error err;
	t_coord coord;

	err = ft_ximgf_setup(x.display, &tex, tex_path);
	if (err)
		return (err);

	coord = ft_map_search_seq(map, comp);

	while (coord.x >= 0)
	{
		ft_ximg_copy(&x.scene, tex, (t_coord){
			coord.x * TILE_SIZE, 
			coord.y * TILE_SIZE
		});
		coord = ft_map_search_seq(map, comp);
	}

	ft_ximg_free(x.display, tex);
	return (OK);
}
