/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_restart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:09:45 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/20 00:22:26 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_game_restart(t_xenv *x, t_game *g)
{
	t_coord start;

	start = ft_map_search(g->map, AVATAR, (t_coord){1, 1});
	
	g->moves = 0;
	g->avatar.x = start.x;
	g->avatar.y = start.y;
	g->avatar.died = false;
	g->avatar.orient = RIGHT;
	x->allow_move = true;

	ft_map_restart(&g->map);
	ft_win_draw(*x, *g);
	ft_draw_anim(x, g);
}
