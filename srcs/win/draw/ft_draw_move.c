/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:11:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/24 00:15:33 by arocha-b         ###   ########.fr       */
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

static t_error ft_update_avatar(t_xenv x, t_game g, t_coord last_pos)
{
	t_error err;

	if (g.avatar.died)
		return (ft_draw_death(x, g));

	err = ft_clear_tile(x, last_pos);
	if (err)
		return (ft_error(err, ERR_RENDSPACE));

	err = ft_draw_comp(x, g, AVATAR);
	if (err)
		return (ft_error(err, ERR_RENDAVATAR));

	return (OK);
}

static bool ft_reset_pos(t_game g, t_coord *last_pos)
{
	if (!last_pos->x || g.won || g.avatar.died)
	{
		*last_pos = ft_map_search(g.map, START_POINT, (t_coord){1, 1});
		return (false);
	}

	if (last_pos->x == g.avatar.x && last_pos->y == g.avatar.y)
		return (true);

	if (g.won)
		return (true);

	return (false);
}

t_error ft_draw_move(t_xenv x, t_game g)
{
	t_error err;
	static t_coord last_pos;

	err = ft_draw_counter(x, g);
	if (err)
		return (ft_error(err, ERR_RENDCOUNT));

	if (ft_reset_pos(g, &last_pos))
		return (OK);

	err = ft_update_avatar(x, g, last_pos);
	if (err)
		return (err);

	if (!g.won && !g.avatar.died)
	{
		last_pos.x = g.avatar.x;
		last_pos.y = g.avatar.y;
	}

	return (OK);
}
