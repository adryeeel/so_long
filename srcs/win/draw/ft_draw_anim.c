/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:39:11 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/29 20:17:26 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_draw_anim(t_xenv *x, t_game *g)
{
	t_error err;
	static size_t frame_n;

	if (frame_n >= 12)
		frame_n = 0;

	if (g->won || g->avatar.died)
		x->allow_move = false;

	if (g->won)
		return (ft_draw_final(x, g, GAME_WON));

	if (g->avatar.died)
		return (ft_draw_final(x, g, GAME_OVER));

	err = ft_draw_frame(*x, g->map, PATROL, frame_n);
	if (err)
		return (ft_error(err, ERR_RENDPATROL));

	err = ft_draw_frame(*x, g->map, COLLECTIBLE, frame_n);
	if (err)
		return (ft_error(err, ERR_RENDCOLL));

	frame_n++;
	return (OK);
}
