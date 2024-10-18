/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_restart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:09:45 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/18 19:24:33 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_reset_collectible(t_game *g)
{
	size_t x;
	size_t y;

	y = -1;
	while (++y < g->map.height)
	{
		x = -1;
		while (++x < g->map.width)
		{
			if (g->map.grid[y][x] == COLLECTED)
				g->map.grid[y][x] = COLLECTIBLE;
		}
	}
}

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

	ft_reset_collectible(g);
	ft_win_draw(*x, *g);
	ft_draw_anim(x, g);
}
