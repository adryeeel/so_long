/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/10 15:22:04 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_move_left(t_game *g)
{
	int x;
	int y;

	y = g->avatar.y;
	x = g->avatar.x - 1;
	g->avatar.orient = LEFT;

	if (g->map.grid[y][x] == WALL)
		return;

	if (g->map.grid[y][x] == COLLECTIBLE)
		g->map.grid[y][x] = SPACE;

	g->avatar.x--;
}
