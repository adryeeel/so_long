/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:33:33 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_move_right(t_game *game)
{
	int x;
	int y;

	y = game->avatar.y;
	x = game->avatar.x + 1;

	if (game->map.grid[y][x] == WALL)
		return;

	if (game->map.grid[y][x] == COLLECTIBLE)
		game->map.grid[y][x] = SPACE;

	game->avatar.x++;
}
