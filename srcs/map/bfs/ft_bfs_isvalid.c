/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_isvalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:13:52 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/02 05:36:50 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_bfs_isvalid(t_map map, t_coord pos, int **visited)
{
	size_t ok;
	t_mapc goal;

	ok = 0;
	goal = ft_bfs_goal(GET, 0);

	if (pos.x >= 0 && pos.x < (int)map.width)
		ok++;

	if (pos.y >= 0 && pos.y < (int)map.height)
		ok++;

	if (!visited[pos.y][pos.x])
		ok++;

	if (map.grid[pos.y][pos.x] != WALL)
		ok++;

	if (goal == COLLECTIBLE && map.grid[pos.y][pos.x] != EXIT_POINT)
		ok++;

	if (goal != COLLECTIBLE)
		return (ok == 4);

	return (ok == 5);
}
