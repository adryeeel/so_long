/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_avatar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:19:52 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 21:07:59 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_avatar(t_xenv x, t_map map, t_coord avatar)
{
	t_ximg tex;
	t_error err;

	err = ft_ximgf_setup(x.display, &tex, AVATAR_IMG_PATH);
	if (err)
		return (err);

	err = ft_draw_comp(x, map, START_POINT, BG_IMG_PATH);
	if (err)
	{
		ft_ximg_free(x.display, tex);
		return (ft_error_coll(err));
	}

	ft_ximg_copy(&x.scene, tex, (t_coord){
		avatar.x * TILE_SIZE, 
		avatar.y * TILE_SIZE
	});

	ft_ximg_free(x.display, tex);
	return (OK);
}
