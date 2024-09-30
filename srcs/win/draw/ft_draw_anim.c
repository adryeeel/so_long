/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:39:11 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:21:49 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define COLL_FRAME_N frame_n % (x.coll.width / TILE_SIZE)

t_error ft_draw_anim(t_xenv x, t_game g)
{
	t_error err;
	static size_t frame_n;

	if (frame_n >= 12)
		frame_n = 0;

	err = ft_draw_move(x, g.map, g.avatar);
	if (err)
		return (ft_error_avatar(err));

	err = ft_draw_coll(x, g, COLL_FRAME_N);
	if (err)
		return (ft_error_coll(err));

	frame_n++;
	return (OK);
}
