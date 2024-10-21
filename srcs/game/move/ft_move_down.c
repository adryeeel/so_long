/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/20 19:05:48 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_move_down(t_game *g)
{
	int x;
	int y;

	if (g->avatar.died)
		return;

	x = g->avatar.x;
	y = g->avatar.y + 1;

	if (g->map.grid[y][x] == WALL)
		return;

	g->moves++;

	if (g->map.grid[y][x] == PATROL)
	{
		g->avatar.died = true;
		return;
	}

	if (g->map.grid[y][x] == EXIT_POINT)
	{
		if (ft_check_won(g->map))
			g->won = true;

		g->moves--;
		return;
	}

	if (g->map.grid[y][x] == COLLECTIBLE)
		g->map.grid[y][x] = COLLECTED;

	g->avatar.y++;
}
