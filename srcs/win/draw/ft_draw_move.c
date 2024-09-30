/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:11:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:17:27 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_move(t_xenv x, t_map map, t_coord avatar)
{
	t_ximg bg;
	t_error err;
	static t_coord last_pos;

	if (last_pos.x == avatar.x && last_pos.y == avatar.y)
		return (OK);

	if (!last_pos.x && !last_pos.y)
		last_pos = avatar;

	err = ft_ximgf_setup(x.display, &bg, BG_IMG_PATH);
	if (err)
		return (ft_error_space(err));

	ft_ximg_copy(&x.scene, bg, (t_coord){
		last_pos.x * TILE_SIZE, 
		last_pos.y * TILE_SIZE
	});

	ft_draw_avatar(x, map, avatar);

	ft_ximg_free(x.display, bg);
	last_pos = avatar;
	return (OK);
}
