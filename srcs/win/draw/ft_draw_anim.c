/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:39:11 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/08 12:19:38 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_anim(t_xenv *x, t_game *g)
{
	t_error err;
	static size_t frame_n;

	if (frame_n >= 12)
	{
		frame_n = 0;
		ft_map_patrol(g->map);
	}

	if (g->won || g->avatar.died)
		x->allow_move = false;

	if (g->won)
		return (ft_draw_final(x, g, GAME_WON));

	if (g->avatar.died)
		return (ft_draw_final(x, g, GAME_OVER));

	err = ft_draw_frame(*x, g->map, ENEMY, frame_n);
	if (err)
		return (ft_error(err, ERR_RENDENEMY));

	err = ft_draw_frame(*x, g->map, COLLECTIBLE, frame_n);
	if (err)
		return (ft_error(err, ERR_RENDCOLL));

	frame_n++;
	return (OK);
}
