/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/20 19:05:21 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_move_left(t_game *g)
{
	int x;
	int y;

	if (g->avatar.died)
		return;

	y = g->avatar.y;
	x = g->avatar.x - 1;
	g->avatar.orient = LEFT;

	if (g->map.grid[y][x] == WALL)
		return;

	g->moves++;

	if (g->map.grid[y][x] == PATROL)
	{
		g->avatar.died = true;
		return;
	}

	if (g->map.grid[y][x] == EXIT_POINT) // ! Fix map path verification to consider exti points as wall when are collectibles in the map. An exit point cannot block the avatar's to reach the collectible, if so, is impossible to win the game.
	{
		if (ft_check_won(g->map))
			g->won = true;

		g->moves--;
		return;
	}

	if (g->map.grid[y][x] == COLLECTIBLE)
		g->map.grid[y][x] = COLLECTED;

	g->avatar.x--;
}
