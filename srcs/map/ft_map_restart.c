/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_restart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:04:34 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 17:19:12 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_reset_coll(t_map *map)
{
	size_t x;
	size_t y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == COLLECTED)
				map->grid[y][x] = COLLECTIBLE;
		}
	}
}

void ft_map_restart(t_map *map)
{
	ft_reset_coll(map);
}