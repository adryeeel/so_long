/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:11:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/15 16:02:56 by arocha-b         ###   ########.fr       */
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

	err = ft_draw_counter(x, g);
	if (err)
		return (ft_error_counter(err));

	if (g.avatar.died)
		return (ft_draw_death(x, g));

	if (last_pos.x == g.avatar.x && last_pos.y == g.avatar.y)
		return (OK);

	if (!last_pos.x)
	{
		last_pos.x = g.avatar.x;
		last_pos.y = g.avatar.y;
	}

	err = ft_clear_tile(x, last_pos);
	if (err)
		return (ft_error_space(err));

	err = ft_draw_comp(x, g, AVATAR);
	if (err)
		return (ft_error_avatar(err));

	last_pos.x = g.avatar.x;
	last_pos.y = g.avatar.y;

	return (OK);
}
