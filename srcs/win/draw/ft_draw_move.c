/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:11:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/10 14:51:58 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static t_error ft_clear_tile(t_xenv x, t_coord coord)
{
	t_ximg tex;
	t_error err;

	err = ft_ximgf_setup(x.display, &tex, SPACE_IMG_PATH);

	if (err)
		return (err);

	ft_draw_at(&x.scene, tex, coord);
	ft_ximg_free(x.display, tex);

	return (OK);
}

t_error ft_draw_move(t_xenv x, t_game g)
{
	t_error err;
	static t_coord last_pos;

	if (last_pos.x == g.avatar.x && last_pos.y == g.avatar.y)
		return (OK);

	if (!last_pos.x)
	{
		last_pos.x = g.avatar.x;
		last_pos.y = g.avatar.y;
	}

	ft_clear_tile(x, last_pos);

	err = ft_draw_comp(x, g, AVATAR);
	if (err)
		return (err);

	last_pos.x = g.avatar.x;
	last_pos.y = g.avatar.y;

	return (OK);
}
