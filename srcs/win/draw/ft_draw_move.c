/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:11:47 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/10 16:44:34 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

	ft_draw_at(&x.scene, x.space, last_pos);

	err = ft_draw_comp(x, g, AVATAR);
	if (err)
		return (err);

	last_pos.x = g.avatar.x;
	last_pos.y = g.avatar.y;

	return (OK);
}
