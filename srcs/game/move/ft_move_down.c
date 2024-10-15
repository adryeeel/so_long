/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/15 15:43:14 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_move_down(t_game *g)
{
	int x;
	int y;

	x = g->avatar.x;
	y = g->avatar.y + 1;

	if (g->map.grid[y][x] == WALL)
		return;

	if (g->map.grid[y][x] == PATROL)
	{
		g->avatar.died = true;
		return;
	}

	if (g->map.grid[y][x] == COLLECTIBLE)
		g->map.grid[y][x] = SPACE;

	g->moves++;
	g->avatar.y++;
}
