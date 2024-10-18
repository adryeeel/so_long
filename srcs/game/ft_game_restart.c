/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_restart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:09:45 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/18 14:39:13 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_game_restart(t_xenv *x, t_game *g)
{
	t_coord start;

	start = ft_map_search(g->map, AVATAR, (t_coord){1, 1});
	g->avatar.x = start.x;
	g->avatar.y = start.y;
	g->avatar.orient = RIGHT;

	g->moves = 0;
	g->avatar.died = false;

	x->fade = false;

	// Restart coins too
	// clear counter digits
	// Fix avatar start position bug

	ft_win_draw(*x, *g);
	ft_draw_anim(x, g);
}
