/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:32:13 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 23:05:24 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_coord ft_map_search(t_map map, t_mapc comp, t_coord start)
{
	t_coord pos;

	pos.x = start.x;
	pos.y = start.y;

	while (map.grid[pos.y])
	{
		while (map.grid[pos.y][pos.x])
		{
			if (map.grid[pos.y][pos.x] == (int)comp)
				return (pos);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}
