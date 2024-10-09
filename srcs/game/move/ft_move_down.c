/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:32:35 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_move_down(t_game *game)
{
	int x;
	int y;

	x = game->avatar.x;
	y = game->avatar.y + 1;

	if (game->map.grid[y][x] == WALL)
		return;

	if (game->map.grid[y][x] == COLLECTIBLE)
		game->map.grid[y][x] = SPACE;

	game->avatar.y++;
}
